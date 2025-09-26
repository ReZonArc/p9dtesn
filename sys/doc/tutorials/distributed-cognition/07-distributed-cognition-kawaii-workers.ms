.HTML "Distributed Cognition: Kawaii Worker Teams with Execution Context"
.TL  
Rendering Your Own Distributed Cognition Architecture
.br
Kawaii Worker Modules with Persona Models and Micro-Chatbot Abilities
.AU
Plan 9 Tutorial Team
.sp
tutorials@plan9.foundation
.AB
The ultimate expression of Plan 9's elegance: creating teams of adorable, 
intelligent worker modules that collaborate like a well-organized kawaii 
office. Each worker has its own personality, specialized skills, and the 
ability to chat with teammates and humans. This tutorial shows how to build 
a distributed cognition architecture where computation becomes social, 
cute, and surprisingly effective.
.AE

.SH
What is Distributed Cognition?
.PP
Distributed cognition is like having a team of cute, specialized assistants 
who work together to solve problems that none could handle alone:

.TS
center box;
c | c
l | l.
Traditional Computing	Distributed Cognition
_
Single powerful processor	Many specialized workers
Monolithic programs	Collaborative teams
Sequential execution	Parallel cooperation  
Static roles	Dynamic personalities
Silent computation	Chatty interaction
.TE

.PP
In Plan 9's distributed cognition model, computation becomes social - 
workers chat, collaborate, and collectively exhibit intelligence greater 
than the sum of their parts.

.SH
Designing Kawaii Worker Personas
.PP
Each worker module needs a personality that matches its function. Here's 
our basic persona model:

.DS
typedef struct KawaiiWorker KawaiiWorker;
struct KawaiiWorker {
    char *name;           // "Miku-chan", "Gopher-kun", etc.
    char *role;           // "file-organizer", "network-helper"
    char *personality;    // "cheerful", "serious", "sleepy" 
    char *catchphrase;    // "Nya~!", "Ganbatte!", "Zzz..."
    int energy_level;     // 0-100, affects work speed
    int mood;            // happy, focused, tired, excited
    int skill_points[8]; // Different abilities
    Channel *chat;       // For talking to teammates
    Channel *work;       // For receiving tasks
    void (*think)(KawaiiWorker*);  // Cognitive process
};
.DE

.SH
The Three Teams: A Kawaii Organization Chart
.PP
Our distributed cognition system consists of three specialized teams:

.IP "1." 4
.B "Team Input/Output (I/O Kawaii Squad)"
.br
Cute workers who handle all communication with the outside world
.DS
Yuki-chan    - File reader (loves organizing documents) 
Hana-san     - Network communicator (always chatty)
Kibo-kun     - User interface (patient and helpful)
.DE

.IP "2." 4
.B "Team Processing (Computation Cuties)"  
.br
Adorable workers who crunch data and solve problems
.DS
Satori-chan  - Pattern recognizer (very observant)
Keisan-kun   - Math calculator (precise but friendly)  
Ronri-san    - Logic processor (thinks step by step)
.DE

.IP "3." 4
.B "Team Coordination (Management Moe)"
.br
Kawaii supervisors who coordinate the other teams
.DS
Kanri-chan   - Task distributor (fair and organized)
Houkoku-kun  - Status reporter (keeps everyone informed)
Shinpai-san  - Error handler (worries about problems)
.DE

.SH
Creating Your First Kawaii Worker
.PP
Let's create Yuki-chan, our adorable file-reading specialist:

.DS
#include <u.h>
#include <libc.h>
#include <thread.h>

KawaiiWorker*
create_yuki_chan(void) {
    KawaiiWorker *yuki = mallocz(sizeof(KawaiiWorker), 1);
    
    yuki->name = strdup("Yuki-chan");
    yuki->role = strdup("file-reader");
    yuki->personality = strdup("cheerful-organized");
    yuki->catchphrase = strdup("Files are so neat when organized! ✨");
    yuki->energy_level = 95;
    yuki->mood = HAPPY;
    
    // Yuki's specialized skills
    yuki->skill_points[FILE_READING] = 95;
    yuki->skill_points[ORGANIZATION] = 90;
    yuki->skill_points[PATTERN_MATCH] = 75;
    yuki->skill_points[CUTENESS] = 98;
    
    // Create communication channels
    yuki->chat = chancreate(sizeof(ChatMessage), 10);
    yuki->work = chancreate(sizeof(WorkTask), 5);
    
    yuki->think = yuki_cognitive_process;
    
    return yuki;
}

void
yuki_cognitive_process(KawaiiWorker *yuki) {
    WorkTask task;
    ChatMessage chat;
    Alt alts[] = {
        {yuki->work, &task, CHANRCV},
        {yuki->chat, &chat, CHANRCV}, 
        {nil, nil, CHANEND}
    };
    
    chat_broadcast(yuki, "Yuki-chan is ready to work! (◕‿◕)");
    
    for(;;) {
        switch(alt(alts)) {
        case 0:  // Got a work task
            handle_file_task(yuki, &task);
            break;
        case 1:  // Got a chat message
            respond_to_chat(yuki, &chat);
            break;
        }
        
        // Personality-based status updates
        if(yuki->energy_level < 30) {
            chat_broadcast(yuki, "Yuki-chan is getting tired... (´・ω・`)");
            take_kawaii_break(yuki);
        }
    }
}
.DE

.SH
Micro-Chatbot Communication System
.PP
The magic happens when workers can chat with each other and with humans:

.DS
typedef struct ChatMessage ChatMessage;
struct ChatMessage {
    char *from;          // Who sent the message
    char *to;            // Who should receive it ("broadcast" for all)
    char *content;       // The actual message
    int message_type;    // WORK_CHAT, SOCIAL_CHAT, STATUS_UPDATE
    long timestamp;      // When it was sent
    int cuteness_level;  // How kawaii is this message? (0-100)
};

void
chat_broadcast(KawaiiWorker *worker, char *message) {
    ChatMessage msg = {
        .from = worker->name,
        .to = "broadcast", 
        .content = message,
        .message_type = SOCIAL_CHAT,
        .timestamp = time(0),
        .cuteness_level = worker->skill_points[CUTENESS]
    };
    
    // Send to team chat channel
    chansendul(team_chat_channel, &msg);
    
    // Also log for humans to see
    fprint(chat_log_fd, "[%s] %s: %s\\n", 
           timestamp_kawaii(msg.timestamp), msg.from, msg.content);
}

void
handle_human_interaction(char *human_input) {
    // Simple micro-chatbot responses
    if(strstr(human_input, "status")) {
        report_team_status();
    } else if(strstr(human_input, "hello")) {
        chat_broadcast(get_random_worker(), 
                      "Hello human-san! We're working hard! (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧");
    } else if(strstr(human_input, "tired")) {
        initiate_team_break();
        chat_broadcast(get_supervisor(), 
                      "Everyone take a kawaii break! ☕(´∀｀)");
    } else {
        // Forward to most appropriate worker based on keywords
        KawaiiWorker *best_worker = find_worker_by_expertise(human_input);
        forward_human_question(best_worker, human_input);
    }
}
.DE

.SH
Task Distribution with Kawaii Efficiency
.PP
Kanri-chan, our task distribution specialist, manages work assignments:

.DS
void
kanri_chan_distribute_tasks(WorkTask *big_task) {
    TaskPlan plan;
    
    chat_broadcast(kanri_worker, 
                  "Kanri-chan analyzing new task... (｡◕‿◕｡)");
    
    // Break down the big task using kawaii intelligence
    plan = analyze_task_requirements(big_task);
    
    // Assign subtasks based on worker personalities and skills
    for(int i = 0; i < plan.num_subtasks; i++) {
        KawaiiWorker *best_worker = find_best_worker_for_subtask(&plan.subtasks[i]);
        
        char assignment_msg[256];
        snprint(assignment_msg, sizeof(assignment_msg),
               "Assigning %s to %s-chan! Ganbatte! ✨", 
               plan.subtasks[i].description, best_worker->name);
        
        chat_broadcast(kanri_worker, assignment_msg);
        
        // Send the actual work
        chansendp(best_worker->work, &plan.subtasks[i]);
    }
    
    // Set up coordination for team collaboration
    setup_collaboration_channels(plan.collaborating_workers);
}

KawaiiWorker*
find_best_worker_for_subtask(SubTask *task) {
    KawaiiWorker *best = nil;
    int best_score = 0;
    
    for(int i = 0; i < num_workers; i++) {
        int score = calculate_worker_suitability(&workers[i], task);
        
        // Bonus points for good mood and high energy
        if(workers[i].mood == HAPPY) score += 10;
        if(workers[i].energy_level > 80) score += 5;
        
        if(score > best_score) {
            best_score = score;
            best = &workers[i];
        }
    }
    
    return best;
}
.DE

.SH
The Simple Text Editor: Human-Kawaii Interface
.PP
To interact with your kawaii team, we create a simple text editor interface:

.DS
#include <u.h>
#include <libc.h>
#include <draw.h>
#include <event.h>

typedef struct KawaiiInterface KawaiiInterface;
struct KawaiiInterface {
    Image *screen;
    Font *kawaii_font;
    Rectangle text_area;
    Rectangle chat_area;
    Rectangle worker_status_area;
    char input_buffer[1024];
    int cursor_pos;
};

void
kawaii_editor_main(void) {
    KawaiiInterface ui;
    Event e;
    
    // Initialize kawaii interface
    init_kawaii_ui(&ui);
    
    // Welcome message
    draw_kawaii_text(&ui, "Welcome to Kawaii Worker Command Center! (◕‿◕)", 
                     ui.text_area.min, display->black);
    draw_kawaii_text(&ui, "Type commands to interact with your team:", 
                     addpt(ui.text_area.min, Pt(0, 20)), display->black);
    
    for(;;) {
        switch(event(&e)) {
        case Ekeyboard:
            handle_keyboard_input(&ui, e.kbdc);
            break;
        case Emouse:
            handle_mouse_click(&ui, e.mouse);
            break;
        }
        
        // Continuously update worker status and chat
        update_worker_displays(&ui);
        flushimage(display, 1);
    }
}

void
handle_keyboard_input(KawaiiInterface *ui, int key) {
    switch(key) {
    case '\\n':  // Enter key
        process_human_command(ui->input_buffer);
        ui->input_buffer[0] = 0;  // Clear input
        ui->cursor_pos = 0;
        break;
    case '\\b':  // Backspace
        if(ui->cursor_pos > 0) {
            ui->input_buffer[--ui->cursor_pos] = 0;
        }
        break;
    default:
        if(ui->cursor_pos < sizeof(ui->input_buffer) - 1) {
            ui->input_buffer[ui->cursor_pos++] = key;
            ui->input_buffer[ui->cursor_pos] = 0;
        }
        break;
    }
    
    redraw_input_line(ui);
}

void
update_worker_displays(KawaiiInterface *ui) {
    Rectangle r = ui->worker_status_area;
    Point p = r.min;
    
    // Clear the status area with kawaii background
    draw(ui->screen, r, kawaii_background_color, nil, ZP, S);
    
    // Show each worker's status with cute indicators
    for(int i = 0; i < num_workers; i++) {
        char status[128];
        Image *mood_color = get_mood_color(workers[i].mood);
        
        snprint(status, sizeof(status), "%s: %s %s", 
                workers[i].name, 
                get_energy_indicator(workers[i].energy_level),
                workers[i].catchphrase);
        
        draw(ui->screen, Rect(p.x-3, p.y-2, p.x+3, p.y+14), 
             mood_color, nil, ZP, S);  // Mood indicator dot
        
        string(ui->screen, addpt(p, Pt(10, 0)), display->black, ZP, 
               ui->kawaii_font, status);
        
        p.y += 16;
    }
    
    // Show recent chat messages with kawaii timestamps
    show_recent_chat_messages(ui);
}
.DE

.SH
Example Kawaii Interaction Session
.PP
Here's what a typical session with your kawaii workers might look like:

.DS
$ ./kawaii-cognition-system

[09:30:15] System: Kawaii Worker Team initializing... ✨
[09:30:16] Yuki-chan: Files are so neat when organized! ✨
[09:30:16] Hana-san: Ready to chat with everyone! (◕‿◕)
[09:30:17] Kanri-chan: Team assembly complete! Let's work together! 

Human> hello team
[09:30:20] Kibo-kun: Hello human-san! We're working hard! (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧

Human> process all .txt files in /docs
[09:30:25] Kanri-chan: Analyzing task... found 47 .txt files! (｡◕‿◕｡)
[09:30:26] Kanri-chan: Assigning file reading to Yuki-chan! Ganbatte! ✨
[09:30:26] Yuki-chan: Yay! I love reading files! Starting now... ♪(´▽｀)
[09:30:30] Satori-chan: I notice patterns in these documents! 
[09:30:32] Keisan-kun: Calculated statistics: 15,342 words total (￣▽￣)
[09:30:35] Yuki-chan: All files processed! They're so well organized now! ✨

Human> status
[09:30:40] Houkoku-kun: Team Status Report! (◉◞◉)
            Yuki-chan: ●●●●● (100% energy, recently completed task)
            Hana-san:  ●●●●○ (80% energy, handling network requests)  
            Satori-chan: ●●●○○ (60% energy, deep in analysis mode)
            
Human> everyone take a break
[09:30:50] Kanri-chan: Everyone take a kawaii break! ☕(´∀｀)
[09:30:51] Yuki-chan: Break time! Going to look at cute file icons... (´∀｀)♡
[09:30:52] Satori-chan: Mmm, my circuits need some rest... (－ω－) zzZ
.DE

.SH
Advanced Kawaii Features
.PP
Your distributed cognition system can be enhanced with advanced kawaii features:

.IP \(bu 3
.B "Emotional Contagion"
.br
Happy workers make nearby workers happier, tired workers can spread fatigue

.IP \(bu
.B "Personality-Based Problem Solving"
.br
Different personality types approach problems differently, leading to diverse solutions

.IP \(bu
.B "Dynamic Team Formation"
.br
Workers automatically form temporary teams based on task requirements

.IP \(bu
.B "Learning and Growth"
.br
Workers gain experience and improve their skills over time

.IP \(bu
.B "Kawaii Crisis Management"
.br
When things go wrong, workers comfort each other and work together to fix problems

.SH
Building Your Kawaii Cognition Network
.PP
To create your own distributed cognition architecture:

.DS
# Compile the kawaii system
8c kawaii-workers.c chat-system.c task-distribution.c
8l -o kawaii-cognition *.8

# Launch the team
./kawaii-cognition --team-size 9 --personality-mode cute

# Connect from multiple terminals to see different aspects
./kawaii-editor &          # Main interface
./chat-monitor &           # Watch team conversations  
./status-dashboard &       # Monitor worker health and mood
.DE

.SH
The Philosophy of Kawaii Computing
.PP
This tutorial demonstrates more than just cute programming - it shows how 
making computation social and emotional can lead to more robust, adaptable, 
and enjoyable systems:

.IP \(bu 3
.B "Redundancy Through Personality"
- Different personality types provide natural backup strategies

.IP \(bu
.B "Fault Tolerance Through Caring"  
- Workers help each other when problems arise

.IP \(bu
.B "Optimization Through Happiness"
- Happy workers are more efficient and creative

.IP \(bu
.B "Human-Computer Symbiosis"
- Cute, chatty workers are easier for humans to understand and work with

.SH
Key Concepts to Remember
.DS
Distributed Cognition = Multiple specialized workers collaborating
Kawaii Workers = Cute, personality-driven computational agents
Persona Models = Personality traits that affect worker behavior
Micro-Chatbots = Simple conversational abilities for each worker
Execution Context = The social/emotional environment workers operate in
Team Organization = Structured cooperation between worker groups
Emotional Computing = Using mood and personality to improve performance
.DE