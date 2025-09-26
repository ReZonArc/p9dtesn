.HTML "Reveal the Hidden Canvas: Your First Service Worker"
.TL
Reveal the Hidden Canvas
.br
Paint Your First Service Worker and Discover System Daemons
.AU
Plan 9 Tutorial Team
.sp
tutorials@plan9.foundation
.AB
Having learned to create visual art through quantized routines, we now reveal 
the hidden canvas of system services. Just as an artist's canvas can be hidden 
behind layers of paint, Plan 9's service canvas is hidden behind the familiar 
interface of files and processes. This tutorial teaches you to paint your first 
service worker - a background daemon that performs useful work while remaining 
invisible to casual observation.
.AE

.SH
The Hidden Canvas: Where Services Live
.PP
In Plan 9, there's a secret canvas where services paint themselves into 
existence. This canvas is hidden in plain sight:

.TS
center box;
c | c | c
l | l | l.
Canvas Layer	What You See	What's Really There
_
Surface	Files in /srv	Service endpoints
Background	Empty directories	Daemon processes  
Foundation	System calls	Service worker routines
Frame	Process table	Service lifecycle management  
.TE

.PP
When you list files in /srv, you're seeing the visible brushstrokes of 
invisible service workers painting functionality onto the system canvas.

.SH
Anatomy of a Service Worker
.PP
A Plan 9 service worker is like an artist who works behind a curtain, 
creating beautiful results while remaining unseen:

.DS
/* Basic service worker structure */
#include <u.h>
#include <libc.h>
#include <thread.h>

typedef struct Service Service;
struct Service {
    char *name;        // Artist's signature
    int fd;           // Paintbrush (communication channel)
    Channel *req;     // Request palette  
    Channel *resp;    // Response canvas
    void (*paint)(Service*);  // The artistic technique
};

void
service_worker_main(void *arg) {
    Service *s = arg;
    
    // The hidden painting loop
    for(;;) {
        wait_for_request(s);    // Canvas preparation
        perform_service(s);     // Apply artistic technique  
        send_response(s);       // Reveal result to client
    }
}
.DE

.SH
Your First Service Worker: The Echo Painter
.PP
Let's create your first service worker - one that paints back whatever 
it receives, like an echo in a canyon:

.DS
#include <u.h>
#include <libc.h>
#include <thread.h>

enum { Stacksize = 8192 };

typedef struct EchoService EchoService;
struct EchoService {
    int srvfd;      // Service announcement canvas
    int clientfd;   // Client communication brush
    char *name;     // Our artistic signature
};

void
echo_painter(void *arg) {
    EchoService *echo = arg;
    char buf[256];
    int n;
    
    print("Echo painter started, listening on %s\\n", echo->name);
    
    // The hidden painting loop - invisible to users
    for(;;) {
        // Wait for someone to give us something to paint
        n = read(echo->clientfd, buf, sizeof buf - 1);
        if(n <= 0) {
            print("Echo painter: client disconnected\\n");
            break;
        }
        
        buf[n] = 0;  // Null-terminate our paint
        
        // Paint it back (echo the message)
        print("Echo painter received: %s", buf);
        write(echo->clientfd, buf, n);
    }
    
    print("Echo painter finished\\n");
    threadexits(nil);
}

void
setup_service_canvas(EchoService *echo) {
    int pfd[2];
    
    // Create our hidden communication canvas
    if(pipe(pfd) < 0) {
        fprint(2, "Cannot create service canvas: %r\\n");
        threadexitsall("pipe failed");
    }
    
    echo->srvfd = pfd[1];    // Our end of the canvas
    echo->clientfd = pfd[0]; // Client's brush
    
    // Announce our service on the hidden canvas
    if(post(echo->name, echo->srvfd) < 0) {
        fprint(2, "Cannot post service %s: %r\\n", echo->name);
        threadexitsall("post failed");
    }
    
    print("Service %s painted onto canvas at /srv/%s\\n", 
          echo->name, echo->name);
}

void
threadmain(int argc, char *argv[]) {
    EchoService echo;
    
    // Choose our artistic signature
    echo.name = (argc > 1) ? argv[1] : "echo-painter";
    
    // Prepare our hidden canvas
    setup_service_canvas(&echo);
    
    // Start painting in the background (daemon mode)
    proccreate(echo_painter, &echo, Stacksize);
    
    print("Echo service worker started. Try:\\n");
    print("  echo 'hello world' > /srv/%s\\n", echo.name);
    print("  cat /srv/%s\\n", echo.name);
    
    // Keep the main thread alive while our painter works
    threadexits(nil);
}
.DE

.SH
Compiling and Painting Your First Service
.PP
To bring your service worker to life:

.DS
# Compile your service worker
8c echo-service.c
8l -o echo-service echo.8

# Paint it onto the service canvas  
./echo-service my-echo &

# Test your hidden painter
echo "Hello, hidden artist!" > /srv/my-echo
cat /srv/my-echo
.DE

.PP
You've just painted your first service worker onto Plan 9's hidden canvas!

.SH
Understanding the Hidden Canvas Architecture
.PP
The service canvas has several layers, like a complex painting:

.IP "1." 4
.B "The /srv Layer (Visible Brushstrokes)"
.DS
ls /srv          # See all active service workers
cat /srv/name    # Interact with a specific service
.DE

.IP "2." 4
.B "The Process Layer (Hidden Artists)"  
.DS
ps               # See service worker processes
kill pid         # Stop a service worker
.DE

.IP "3." 4
.B "The Communication Layer (Invisible Brushes)"
.DS
# Service workers communicate through:
pipes()          # Anonymous communication channels
post()           # Publishing services to /srv
mount()          # Attaching services to namespaces
.DE

.SH
Advanced Service Painting: Multi-Channel Workers
.PP
Sophisticated service workers can paint on multiple canvases simultaneously:

.DS
typedef struct MultiService MultiService;
struct MultiService {
    char *name;
    int nchannels;           // Number of painting surfaces
    Channel **requests;      // Multiple request palettes
    Channel **responses;     // Multiple response canvases
    void (*painters[8])(MultiService*, int);  // Different painting techniques
};

void
multi_service_coordinator(void *arg) {
    MultiService *ms = arg;
    Alt alts[9];  // 8 channels + timeout
    int i;
    
    // Set up painting coordination
    for(i = 0; i < ms->nchannels; i++) {
        alts[i].c = ms->requests[i];
        alts[i].v = nil;
        alts[i].op = CHANRCV;
    }
    alts[ms->nchannels].op = CHANEND;
    
    // Coordinate multiple painters
    for(;;) {
        switch(alt(alts)) {
        case 0 ... 7:  // One of our painting channels needs attention
            i = ... ; // Determine which channel
            ms->painters[i](ms, i);  // Apply appropriate technique
            break;
        }
    }
}
.DE

.SH
Service Worker Lifecycle: From Birth to Death
.PP
Service workers have a natural lifecycle, like paintings in a gallery:

.IP \(bu 3
.B "Birth - Service Creation"
.DS
proccreate(service_main, &service_data, Stacksize);
post(service_name, service_fd);  // Birth announcement
.DE

.IP \(bu
.B "Growth - Service Registration and Discovery"
.DS
# Other processes discover the new service
ls /srv | grep service_name
# Service becomes available for use
.DE

.IP \(bu
.B "Maturity - Active Service Period"
.DS
# Service processes requests, performs work
# Maintains state, serves clients
# Adapts to changing demands
.DE

.IP \(bu
.B "Death - Service Cleanup"
.DS
remove("/srv/service_name");  // Remove from service canvas
threadexitsall("service shutdown");  // Clean death
.DE

.SH
Daemon Patterns: Different Service Painting Styles
.PP
Just as artists have different styles, service workers follow different patterns:

.IP "1." 4
.B "The Steady Worker (Classic Daemon)"
.br
Continuously processes requests in a loop
.DS
for(;;) {
    request = wait_for_work();
    result = process_request(request);
    send_result(result);
}
.DE

.IP "2." 4
.B "The Event Artist (Event-Driven Daemon)"
.br
Responds to specific events or signals
.DS
// Waits quietly until something interesting happens
alt_channels = setup_event_channels();
for(;;) {
    event = alt(alt_channels);
    handle_event(event);
}
.DE

.IP "3." 4
.B "The Batch Painter (Periodic Daemon)"
.br
Wakes up periodically to do work
.DS
for(;;) {
    sleep(interval);
    batch_work = collect_pending_work();
    process_batch(batch_work);
}
.DE

.IP "4." 4
.B "The Reactive Creator (On-Demand Daemon)"
.br
Creates new workers as needed
.DS
for(;;) {
    client = accept_connection();
    proccreate(handle_client, client, Stacksize);
}
.DE

.SH
Service Discovery: Finding Hidden Artists
.PP
Plan 9 provides elegant ways to discover service workers on the hidden canvas:

.DS
# Direct discovery - see what services are available
ls /srv

# Namespace discovery - see what's mounted where  
cat /proc/*/ns | grep srv

# Process discovery - see what daemons are running
ps | grep -v '\\[' | grep daemon

# Network discovery - find remote services
cs  # Connection server helps find network services
.DE

.SH
Your Service Worker Toolkit
.PP
Essential tools for painting service workers:

.IP \(bu 3
.B "Communication Brushes"
.DS
pipe()          # Create communication channels
post()          # Publish service to /srv  
mount()         # Attach service to namespace
bind()          # Connect services together
.DE

.IP \(bu
.B "Concurrency Paint"
.DS
proccreate()    # Create background painters
threadcreate()  # Create lightweight workers  
Channel        // Coordinate between painters
alt()          // Wait on multiple painting channels
.DE

.IP \(bu
.B "Lifecycle Management"
.DS
threadnotify()  // Handle painting interruptions
atexit()       // Cleanup when painting ends
threadexits()  // Graceful painter shutdown
.DE

.SH
From Service Workers to Distributed Cognition
.PP
Your first service worker is like a single neuron in a brain. The next step 
is connecting multiple service workers into teams that exhibit collective 
intelligence - distributed cognition architectures where multiple simple 
workers collaborate to solve complex problems.

.PP
Just as individual brush strokes combine to create masterpiece paintings, 
individual service workers combine to create masterpiece distributed systems.

.SH
Key Concepts to Remember
.DS
Hidden Canvas = The /srv filesystem where services appear
Service Worker = Background daemon that provides functionality
Painting = The process of creating and running services  
Brushes = Communication channels (pipes, files, networks)
Artists = The daemon processes doing the work
Gallery = The process table showing active services
Lifecycle = Birth, growth, maturity, and death of services
.DE