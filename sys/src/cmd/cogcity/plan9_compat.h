#ifndef PLAN9_COMPAT_H
#define PLAN9_COMPAT_H

/*
 * Plan 9 Compatibility Layer for Linux/Unix Systems
 * Provides Plan 9-style threading and channel operations
 */

#ifdef LINUX_BUILD

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <math.h>
#include <time.h>
#include <errno.h>
#include <stdint.h>

/* Plan 9 style types */
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef long long vlong;
typedef unsigned long long uvlong;

/* Channel implementation using pthread */
typedef struct Channel Channel;
typedef struct Alt Alt;

struct Channel {
    void *buf;
    int elemsize;
    int bufsize;
    int nbuf;
    int off;
    pthread_mutex_t lock;
    pthread_cond_t notempty;
    pthread_cond_t notfull;
    int closed;
};

struct Alt {
    Channel *c;
    void *v;
    int op;
    char *err;
    int entryno;
};

/* Alt operations */
enum {
    CHANRCV = 1,
    CHANSND,
    CHANNOP,
    CHANNOBLK,
    CHANEND
};

/* Function prototypes */
Channel* chancreate(int elemsize, int bufsize);
void chanfree(Channel *c);
int chansend(Channel *c, void *v);
int chanrecv(Channel *c, void *v);
int channbsend(Channel *c, void *v);
int channbrecv(Channel *c, void *v);
int alt(Alt *alts);
void* recvp(Channel *c);
int sendp(Channel *c, void *v);
void* nbrecvp(Channel *c);
int nbsendp(Channel *c, void *v);
int sendul(Channel *c, ulong v);
ulong recvul(Channel *c);
int nbsendul(Channel *c, ulong v);
int nbrecvul(Channel *c, ulong *v);
int chanlen(Channel *c);
void chanclose(Channel *c);

/* Threading */
void threadcreate(void (*fn)(void*), void *arg, int stack);
void threadmain(int argc, char *argv[]);
int main(int argc, char *argv[]);

/* Memory allocation */
void* mallocz(int size, int zero);

/* Argument parsing */
extern int ARGC;
extern char **ARGV;
extern char *ARGF(void);
extern char *EARGF(void (*usage)(void));

#define ARGBEGIN for(ARGC--, ARGV++; *ARGV && **ARGV == '-' && ARGV[0][1]; ARGC--, ARGV++) { \
    char *_args = &ARGV[0][1]; \
    while(*_args) switch(*_args++)
    
#define ARGEND }

/* Plan 9 style constants */
#define nil NULL

/* Print functions */
#define print printf
#define fprint(fd, ...) fprintf((fd) == 2 ? stderr : stdout, __VA_ARGS__)
#define snprint snprintf

/* Exit */
void exits(char *msg);

/* Sleep (rename to avoid conflict) */
void p9sleep(int ms);
#define sleep p9sleep

/* String functions */
char* strdup(const char *s);

#else

/* Regular Plan 9 includes */
#include <u.h>
#include <libc.h>
#include <thread.h>

#endif /* LINUX_BUILD */

#endif /* PLAN9_COMPAT_H */