#include "plan9_compat.h"

#ifdef LINUX_BUILD

/*
 * Plan 9 Compatibility Implementation for Linux/Unix
 */

/* Global variables for argument parsing */
int ARGC;
char **ARGV;

/* Channel implementation */
Channel*
chancreate(int elemsize, int bufsize) {
    Channel *c = malloc(sizeof(Channel));
    if (!c) return nil;
    
    c->elemsize = elemsize;
    c->bufsize = bufsize;
    c->nbuf = 0;
    c->off = 0;
    c->closed = 0;
    
    if (bufsize > 0) {
        c->buf = malloc(elemsize * bufsize);
        if (!c->buf) {
            free(c);
            return nil;
        }
    } else {
        c->buf = nil;
    }
    
    pthread_mutex_init(&c->lock, nil);
    pthread_cond_init(&c->notempty, nil);
    pthread_cond_init(&c->notfull, nil);
    
    return c;
}

void
chanfree(Channel *c) {
    if (!c) return;
    
    pthread_mutex_destroy(&c->lock);
    pthread_cond_destroy(&c->notempty);
    pthread_cond_destroy(&c->notfull);
    
    if (c->buf) free(c->buf);
    free(c);
}

int
chansend(Channel *c, void *v) {
    if (!c) return -1;
    
    pthread_mutex_lock(&c->lock);
    
    if (c->closed) {
        pthread_mutex_unlock(&c->lock);
        return -1;
    }
    
    while (c->nbuf >= c->bufsize && !c->closed) {
        pthread_cond_wait(&c->notfull, &c->lock);
    }
    
    if (c->closed) {
        pthread_mutex_unlock(&c->lock);
        return -1;
    }
    
    if (c->buf) {
        char *dst = (char*)c->buf + ((c->off + c->nbuf) % c->bufsize) * c->elemsize;
        memcpy(dst, v, c->elemsize);
    }
    c->nbuf++;
    
    pthread_cond_signal(&c->notempty);
    pthread_mutex_unlock(&c->lock);
    
    return 1;
}

int
chanrecv(Channel *c, void *v) {
    if (!c) return -1;
    
    pthread_mutex_lock(&c->lock);
    
    while (c->nbuf <= 0 && !c->closed) {
        pthread_cond_wait(&c->notempty, &c->lock);
    }
    
    if (c->nbuf <= 0 && c->closed) {
        pthread_mutex_unlock(&c->lock);
        return -1;
    }
    
    if (c->buf) {
        char *src = (char*)c->buf + c->off * c->elemsize;
        memcpy(v, src, c->elemsize);
    }
    
    c->off = (c->off + 1) % c->bufsize;
    c->nbuf--;
    
    pthread_cond_signal(&c->notfull);
    pthread_mutex_unlock(&c->lock);
    
    return 1;
}

int
channbsend(Channel *c, void *v) {
    if (!c) return 0;
    
    if (pthread_mutex_trylock(&c->lock) != 0) {
        return 0;
    }
    
    if (c->closed || c->nbuf >= c->bufsize) {
        pthread_mutex_unlock(&c->lock);
        return 0;
    }
    
    if (c->buf) {
        char *dst = (char*)c->buf + ((c->off + c->nbuf) % c->bufsize) * c->elemsize;
        memcpy(dst, v, c->elemsize);
    }
    c->nbuf++;
    
    pthread_cond_signal(&c->notempty);
    pthread_mutex_unlock(&c->lock);
    
    return 1;
}

int
channbrecv(Channel *c, void *v) {
    if (!c) return 0;
    
    if (pthread_mutex_trylock(&c->lock) != 0) {
        return 0;
    }
    
    if (c->nbuf <= 0) {
        pthread_mutex_unlock(&c->lock);
        return 0;
    }
    
    if (c->buf) {
        char *src = (char*)c->buf + c->off * c->elemsize;
        memcpy(v, src, c->elemsize);
    }
    
    c->off = (c->off + 1) % c->bufsize;
    c->nbuf--;
    
    pthread_cond_signal(&c->notfull);
    pthread_mutex_unlock(&c->lock);
    
    return 1;
}

int
alt(Alt *alts) {
    // Simplified alt implementation - just try each channel once
    for (int i = 0; alts[i].op != CHANEND; i++) {
        if (alts[i].op == CHANNOBLK) {
            return i;
        }
        
        if (alts[i].op == CHANRCV) {
            if (channbrecv(alts[i].c, alts[i].v)) {
                return i;
            }
        } else if (alts[i].op == CHANSND) {
            if (channbsend(alts[i].c, alts[i].v)) {
                return i;
            }
        }
    }
    
    // If no channel ready, block on first available
    for (int i = 0; alts[i].op != CHANEND; i++) {
        if (alts[i].op == CHANRCV) {
            if (chanrecv(alts[i].c, alts[i].v) > 0) {
                return i;
            }
        } else if (alts[i].op == CHANSND) {
            if (chansend(alts[i].c, alts[i].v) > 0) {
                return i;
            }
        }
    }
    
    return -1;
}

void*
recvp(Channel *c) {
    void *v;
    if (chanrecv(c, &v) > 0) {
        return v;
    }
    return nil;
}

int
sendp(Channel *c, void *v) {
    return chansend(c, &v);
}

void*
nbrecvp(Channel *c) {
    void *v;
    if (channbrecv(c, &v) > 0) {
        return v;
    }
    return nil;
}

int
nbsendp(Channel *c, void *v) {
    return channbsend(c, &v);
}

int
sendul(Channel *c, ulong v) {
    return chansend(c, &v);
}

ulong
recvul(Channel *c) {
    ulong v;
    if (chanrecv(c, &v) > 0) {
        return v;
    }
    return 0;
}

int
nbsendul(Channel *c, ulong v) {
    return channbsend(c, &v);
}

int
nbrecvul(Channel *c, ulong *v) {
    return channbrecv(c, v);
}

int
chanlen(Channel *c) {
    if (!c) return 0;
    
    pthread_mutex_lock(&c->lock);
    int len = c->nbuf;
    pthread_mutex_unlock(&c->lock);
    
    return len;
}

void
chanclose(Channel *c) {
    if (!c) return;
    
    pthread_mutex_lock(&c->lock);
    c->closed = 1;
    pthread_cond_broadcast(&c->notempty);
    pthread_cond_broadcast(&c->notfull);
    pthread_mutex_unlock(&c->lock);
}

/* Threading */
struct thread_arg {
    void (*fn)(void*);
    void *arg;
};

static void*
thread_wrapper(void *arg) {
    struct thread_arg *targ = arg;
    targ->fn(targ->arg);
    free(targ);
    return nil;
}

void
threadcreate(void (*fn)(void*), void *arg, int stack) {
    (void)stack;  // Ignore stack size
    
    struct thread_arg *targ = malloc(sizeof(struct thread_arg));
    targ->fn = fn;
    targ->arg = arg;
    
    pthread_t thread;
    pthread_create(&thread, nil, thread_wrapper, targ);
    pthread_detach(thread);  // Don't wait for thread completion
}

#ifndef SAFE_DEMO
int
main(int argc, char *argv[]) {
    ARGC = argc;
    ARGV = argv;
    threadmain(argc, argv);
    return 0;
}
#endif

/* Memory allocation */
void*
mallocz(int size, int zero) {
    void *p = malloc(size);
    if (p && zero) {
        memset(p, 0, size);
    }
    return p;
}

/* Argument parsing */
static int arg_index = 0;
static int char_index = 0;

char*
ARGF(void) {
    if (arg_index >= ARGC) return nil;
    
    char *arg = ARGV[arg_index];
    if (arg[0] == '-' && char_index < strlen(arg) - 1) {
        char_index++;
        if (char_index >= strlen(arg) - 1) {
            arg_index++;
            char_index = 0;
        }
    } else {
        arg_index++;
        char_index = 0;
    }
    
    if (arg_index >= ARGC) return nil;
    return ARGV[arg_index];
}

char*
EARGF(void (*usage)(void)) {
    char *s = ARGF();
    if (s == nil) {
        if (usage) usage();
        exit(1);
    }
    return s;
}

/* Exit */
void
exits(char *msg) {
    if (msg && *msg) {
        fprintf(stderr, "%s\n", msg);
        exit(1);
    }
    exit(0);
}

/* Sleep */
void
p9sleep(int ms) {
    usleep(ms * 1000);
}

#endif /* LINUX_BUILD */