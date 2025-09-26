.HTML "Plan 9 Beginner Tutorial Series: From Drawing Terminals to Kawaii Cognition"
.TL
Plan 9 Beginner Tutorial Series
.br
From Drawing Terminals to Kawaii Distributed Cognition
.AU
Plan 9 Tutorial Team
.sp
tutorials@plan9.foundation
.AB
A progressive series of tutorials that transforms the often intimidating world 
of Plan 9 systems programming into an accessible, creative journey. Starting 
with the simple concept of "drawing a terminal," we progress through kernels 
as seeds, fonts as gestures, vector graphics, service workers, and culminate 
in building adorable distributed cognition architectures with chatty kawaii 
worker modules.
.AE

.SH
The Learning Journey: A Progressive Path
.PP
This tutorial series is designed as a complete learning path where each 
concept builds naturally on the previous ones:

.TS
center box;
c | c | c
l | l | l.
Tutorial	Core Concept	Key Metaphor
_
01. Drawing a Terminal	Remote connection	Artist painting distant lands
02. Drawing a Kernel	System initialization	Creating living artwork
03. Kernels as Seeds	System growth	Digital ecosystems  
04. Fonts as Gestures	Typography	Language of movement
05. Vector Graphics	Resolution independence	Quantized techniques
06. Service Workers	Background services	Hidden canvas artists
07. Distributed Cognition	Collaborative computing	Kawaii office teams
.TE

.SH
Tutorial Overview and Prerequisites

.IP "1." 4
.B "Drawing a Terminal (drawterm-beginners/01-drawing-a-terminal.ms)"
.br
.I "Prerequisites: Basic computer literacy"
.br
Learn how drawterm literally "draws" a terminal window that connects to 
distant Plan 9 systems. Understand the artistic metaphor behind remote 
terminal connections.

.IP "2." 4
.B "Drawing a Kernel (drawkern/02-drawing-a-kernel.ms)"  
.br
.I "Prerequisites: Understanding of drawterm concept"
.br
Extend the drawing metaphor to system kernels - learn how Plan 9 kernels 
are "drawn" into existence using the same principles as drawterm, but 
creating entire systems rather than just windows.

.IP "3." 4
.B "Kernels as Seeds (kernels-as-seeds/03-kernels-as-seeds.ms)"
.br
.I "Prerequisites: Basic understanding of kernels"
.br
Explore how kernels are like seeds containing the DNA for entire computing 
ecosystems. Learn about distributed growth, seasonal cycles, and system 
evolution.

.IP "4." 4
.B "Fonts as Gestures (fonts-as-gestures/04-fonts-as-gestures.ms)"
.br
.I "Prerequisites: Familiarity with Plan 9's file system"
.br
Revolutionary approach to typography - understand fonts as dynamic gestures 
rather than static shapes. Learn how Plan 9's font system enables true 
resolution independence.

.IP "5." 4
.B "Vector Graphics (vector-graphics/05-vector-graphics-dynamic-resolution.ms)"
.br
.I "Prerequisites: Understanding of gestural concepts"
.br
Master quantized routines of applied technique - how vector graphics encode 
artistic methods rather than just results. Build sequences that create 
generative visual elements.

.IP "6." 4
.B "Service Workers (service-workers/06-reveal-hidden-canvas-service-workers.ms)"
.br
.I "Prerequisites: Basic C programming, understanding of processes"
.br
Reveal Plan 9's hidden service canvas and paint your first service worker. 
Learn about daemons, background services, and the /srv filesystem.

.IP "7." 4
.B "Distributed Cognition (distributed-cognition/07-distributed-cognition-kawaii-workers.ms)"
.br
.I "Prerequisites: All previous tutorials, intermediate C programming"
.br
Create teams of kawaii worker modules with personality models and micro-chatbot 
abilities. Build a complete distributed cognition architecture with adorable, 
intelligent agents.

.SH
How to Use This Tutorial Series

.IP \(bu 3
.B "Sequential Learning"
.br
Work through tutorials in order - each builds on concepts from previous ones

.IP \(bu
.B "Hands-On Practice"
.br
Every tutorial includes practical exercises and working code examples

.IP \(bu
.B "Creative Exploration"
.br
Use the metaphors and analogies to develop your own understanding

.IP \(bu
.B "Community Building"
.br
Share your kawaii workers and creative implementations with others

.SH
Tutorial Files and Organization

.DS
sys/doc/tutorials/
├── README.ms                           (this file)
├── drawterm-beginners/
│   └── 01-drawing-a-terminal.ms
├── drawkern/
│   └── 02-drawing-a-kernel.ms
├── kernels-as-seeds/
│   └── 03-kernels-as-seeds.ms
├── fonts-as-gestures/
│   └── 04-fonts-as-gestures.ms
├── vector-graphics/
│   └── 05-vector-graphics-dynamic-resolution.ms
├── service-workers/
│   └── 06-reveal-hidden-canvas-service-workers.ms
└── distributed-cognition/
    └── 07-distributed-cognition-kawaii-workers.ms
.DE

.SH
Building the Example Code

.PP
Many tutorials include working code examples. To build and run them:

.DS
# Navigate to the Plan 9 source tree
cd /sys/src/cmd/unix/drawterm

# Build drawterm (needed for tutorial 1)
CONF=unix make

# For tutorials with custom code examples:
cd /sys/doc/tutorials/service-workers
8c echo-service.c && 8l -o echo-service echo.8

cd /sys/doc/tutorials/distributed-cognition  
8c kawaii-workers.c chat-system.c task-distribution.c
8l -o kawaii-cognition *.8
.DE

.SH
The Philosophy Behind the Tutorials

.PP
These tutorials embody several key educational principles:

.IP \(bu 3
.B "Metaphorical Learning"
.br
Complex technical concepts are introduced through familiar, engaging metaphors

.IP \(bu
.B "Progressive Complexity"
.br
Each tutorial adds just enough new concepts to challenge without overwhelming

.IP \(bu
.B "Creative Expression"
.br
Technical concepts are presented as forms of creative expression and artistry

.IP \(bu
.B "Emotional Engagement"
.br
The kawaii aesthetic makes learning more enjoyable and memorable

.IP \(bu
.B "Practical Application"
.br
Every concept is tied to working code and real-world usage

.SH
Extending the Tutorials

.PP
These tutorials provide a foundation for further exploration:

.IP \(bu 3
.B "Advanced Drawterm"
.br
Explore drawterm's graphics capabilities, multiple connections, and scripting

.IP \(bu
.B "Kernel Hacking"
.br
Use the seed metaphor to understand kernel module development

.IP \(bu
.B "Typography Systems"
.br
Build your own gestural font renderer or font design tools

.IP \(bu
.B "Graphics Programming"
.br
Create sophisticated vector graphics applications using Plan 9's libdraw

.IP \(bu
.B "Distributed Systems"
.br
Expand the kawaii worker concept into full distributed computing platforms

.SH
Community and Contributions

.PP
These tutorials are living documents that grow with the community:

.IP \(bu 3
.B "Share Your Kawaii Workers"
.br
Post your creative worker implementations and personality models

.IP \(bu
.B "Extend the Metaphors"
.br
Develop new analogies and teaching approaches for other Plan 9 concepts

.IP \(bu
.B "Translation Projects"
.br
Translate tutorials to other languages while preserving the kawaii spirit

.IP \(bu
.B "Tool Development"
.br
Create visual tools and editors that embody the tutorial concepts

.SH
Troubleshooting and Support

.PP
If you encounter issues while working through the tutorials:

.IP "1." 4
Check that you have a working Plan 9 system or drawterm installation

.IP "2." 4
Ensure you have the necessary compilers (8c, 8l) and libraries installed

.IP "3." 4
Verify file paths match your Plan 9 system configuration

.IP "4." 4
Join the Plan 9 community forums for help with specific technical issues

.IP "5." 4
Remember: the goal is learning and creativity, not perfect implementation

.SH
The Journey Continues...

.PP
Completing this tutorial series is just the beginning. You'll have developed:

.IP \(bu 3
A deep, intuitive understanding of Plan 9's design philosophy
.IP \(bu
Practical skills in system programming and distributed computing
.IP \(bu
A creative approach to technical problem-solving
.IP \(bu
The ability to make complex systems approachable and engaging
.IP \(bu
A team of adorable kawaii workers to help with future projects

.PP
Welcome to the wonderful world of Plan 9, where computing is creative, 
systems are social, and even the most complex architectures can be 
kawaii! (◕‿◕)✨

.SH
Quick Reference: Key Concepts Across All Tutorials

.DS
Drawing = Creating/initializing systems and connections
Canvas = The space where computation happens (screens, filesystems, networks)
Gestures = Dynamic, expressive actions rather than static states  
Seeds = Small components containing blueprints for larger systems
Quantization = Breaking continuous processes into discrete, reproducible steps
Service Workers = Background agents providing functionality
Kawaii Computing = Making systems social, emotional, and adorable
Distributed Cognition = Multiple agents collaborating to exhibit intelligence
.DE