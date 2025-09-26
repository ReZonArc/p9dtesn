/*
 * Yuki-chan: A Simple Kawaii File Worker
 * Demonstrates basic kawaii worker concepts from tutorial 07
 */

#include <u.h>
#include <libc.h>
#include <thread.h>

enum {
    STACKSIZE = 8192,
    MAXMSG = 256,
    HAPPY = 1,
    FOCUSED = 2,
    TIRED = 3
};

typedef struct KawaiiWorker KawaiiWorker;
struct KawaiiWorker {
    char *name;
    char *role;
    char *catchphrase;
    int energy_level;    // 0-100
    int mood;           // HAPPY, FOCUSED, TIRED
    int files_processed;
    Channel *chat;
    Channel *work;
};

typedef struct WorkTask WorkTask;
struct WorkTask {
    char *filename;
    char *operation;  // "read", "organize", "analyze"
};

typedef struct ChatMessage ChatMessage;
struct ChatMessage {
    char *from;
    char *content;
    long timestamp;
};

/* Global chat log for demonstration */
int chatlogfd = -1;

void
kawaii_log(char *from, char *message)
{
    char timestamp[32];
    long now = time(0);
    
    strftime(timestamp, sizeof(timestamp), "%H:%M:%S", localtime(&now));
    
    if(chatlogfd >= 0) {
        fprint(chatlogfd, "[%s] %s: %s\n", timestamp, from, message);
    }
    print("[%s] %s: %s\n", timestamp, from, message);
}

void
yuki_process_file(KawaiiWorker *yuki, WorkTask *task)
{
    char logmsg[MAXMSG];
    int fd;
    Dir *d;
    
    yuki->energy_level -= 5;  // Work uses energy
    
    if(strcmp(task->operation, "read") == 0) {
        fd = open(task->filename, OREAD);
        if(fd < 0) {
            snprint(logmsg, sizeof(logmsg), 
                   "Eh? I can't read %s... (´・ω・`)", task->filename);
            kawaii_log(yuki->name, logmsg);
            return;
        }
        
        d = dirfstat(fd);
        if(d == nil) {
            close(fd);
            snprint(logmsg, sizeof(logmsg), 
                   "File %s is being mysterious... (・・?)", task->filename);
            kawaii_log(yuki->name, logmsg);
            return;
        }
        
        snprint(logmsg, sizeof(logmsg),
               "Reading %s (%lld bytes)... so organized! ✨", 
               task->filename, d->length);
        kawaii_log(yuki->name, logmsg);
        
        close(fd);
        free(d);
        yuki->files_processed++;
        
        if(yuki->files_processed % 5 == 0) {
            snprint(logmsg, sizeof(logmsg),
                   "Processed %d files! I love organizing! (◕‿◕)", 
                   yuki->files_processed);
            kawaii_log(yuki->name, logmsg);
        }
    }
    
    /* Adjust mood based on energy */
    if(yuki->energy_level < 30) {
        yuki->mood = TIRED;
    } else if(yuki->energy_level > 80) {
        yuki->mood = HAPPY;
    } else {
        yuki->mood = FOCUSED;
    }
}

void
yuki_take_break(KawaiiWorker *yuki)
{
    char logmsg[MAXMSG];
    
    snprint(logmsg, sizeof(logmsg), 
           "Taking a kawaii break... looking at pretty file icons (´∀｀)♡");
    kawaii_log(yuki->name, logmsg);
    
    sleep(1000);  // 1 second break
    yuki->energy_level = min(100, yuki->energy_level + 20);
    yuki->mood = HAPPY;
    
    kawaii_log(yuki->name, "Break finished! Ready to work again! ✨");
}

void
yuki_worker_main(void *arg)
{
    KawaiiWorker *yuki = arg;
    WorkTask task;
    ChatMessage chat;
    char logmsg[MAXMSG];
    
    Alt alts[] = {
        {yuki->work, &task, CHANRCV},
        {yuki->chat, &chat, CHANRCV},
        {nil, nil, CHANEND}
    };
    
    kawaii_log(yuki->name, yuki->catchphrase);
    
    for(;;) {
        switch(alt(alts)) {
        case 0:  /* Got work task */
            yuki_process_file(yuki, &task);
            
            if(yuki->energy_level < 30) {
                yuki_take_break(yuki);
            }
            break;
            
        case 1:  /* Got chat message */
            if(strcmp(chat.content, "status") == 0) {
                char *mood_emoji;
                switch(yuki->mood) {
                case HAPPY: mood_emoji = "(◕‿◕)"; break;
                case FOCUSED: mood_emoji = "(｡◕‿◕｡)"; break;
                case TIRED: mood_emoji = "(´・ω・`)"; break;
                default: mood_emoji = "(・・?)"; break;
                }
                
                snprint(logmsg, sizeof(logmsg),
                       "Energy: %d%%, Files: %d, Mood: %s", 
                       yuki->energy_level, yuki->files_processed, mood_emoji);
                kawaii_log(yuki->name, logmsg);
            } else if(strstr(chat.content, "hello")) {
                kawaii_log(yuki->name, "Hello! Ready to organize files! (◕‿◕)");
            }
            break;
        }
    }
}

KawaiiWorker*
create_yuki_chan(void)
{
    KawaiiWorker *yuki;
    
    yuki = mallocz(sizeof(KawaiiWorker), 1);
    yuki->name = strdup("Yuki-chan");
    yuki->role = strdup("file-organizer");
    yuki->catchphrase = strdup("Files are so neat when organized! ✨");
    yuki->energy_level = 95;
    yuki->mood = HAPPY;
    yuki->files_processed = 0;
    
    yuki->chat = chancreate(sizeof(ChatMessage), 10);
    yuki->work = chancreate(sizeof(WorkTask), 5);
    
    return yuki;
}

void
threadmain(int argc, char *argv[])
{
    KawaiiWorker *yuki;
    WorkTask task;
    ChatMessage chat;
    char input[256];
    int i;
    
    /* Set up chat log */
    chatlogfd = create("/tmp/yuki-chat.log", OWRITE, 0644);
    if(chatlogfd < 0) {
        chatlogfd = 1;  /* stdout */
    }
    
    /* Create our kawaii worker */
    yuki = create_yuki_chan();
    
    /* Start the worker thread */
    proccreate(yuki_worker_main, yuki, STACKSIZE);
    
    print("Yuki-chan File Organizer Demo\n");
    print("Commands:\n");
    print("  read <filename>  - Ask Yuki to read a file\n");
    print("  hello           - Say hello to Yuki\n"); 
    print("  status          - Check Yuki's status\n");
    print("  quit            - Exit\n\n");
    
    /* Simple command interface */
    for(;;) {
        print("> ");
        if(fgets(input, sizeof(input), stdin) == nil)
            break;
            
        /* Remove newline */
        for(i = 0; input[i]; i++) {
            if(input[i] == '\n') {
                input[i] = 0;
                break;
            }
        }
        
        if(strcmp(input, "quit") == 0) {
            break;
        } else if(strncmp(input, "read ", 5) == 0) {
            task.filename = strdup(input + 5);
            task.operation = "read";
            chansendul(yuki->work, task);
        } else if(strstr(input, "hello") || strstr(input, "status")) {
            chat.from = "Human";
            chat.content = strdup(input);
            chat.timestamp = time(0);
            chansendul(yuki->chat, chat);
        } else {
            print("Unknown command. Try 'hello', 'status', 'read <file>', or 'quit'\n");
        }
    }
    
    kawaii_log("System", "Shutting down kawaii workers... (´∀｀)");
    threadexitsall(nil);
}