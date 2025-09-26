.HTML "Drawing a Kernel: From Terminal to System Core"
.TL
Drawing a Kernel (Drawkern)
.br
From Terminal Windows to System Hearts
.AU
Plan 9 Tutorial Team
.sp  
tutorials@plan9.foundation
.AB
Having learned to "draw a terminal" to connect to distant lands, we now venture 
deeper - imagine drawing not just a window into a system, but drawing the very 
heart of that system itself. This is "drawkern" - drawing a kernel, the living 
core that makes everything else possible.
.AE

.SH
From Canvas to Living System
.PP
While drawterm painted a window into a distant system, drawkern takes the same 
fundamental drawing principles and applies them to create something far more 
profound - a complete system kernel. Think of it this way:

.IP \(bu 3
.B "Drawterm"
- Paints a window into an existing system
.IP \(bu  
.B "Drawkern"
- Paints the system itself into existence

.PP
It's the difference between painting a picture of a garden versus planting and 
growing the garden itself. Both use the same artistic principles, but one creates 
a representation while the other creates reality.

.SH
The Kernel as Artwork
.PP
A kernel might seem like a dry, technical thing, but in Plan 9's philosophy, 
it's actually a beautiful work of art - a carefully composed system where every 
component is elegantly designed and perfectly placed.

.PP
When we "draw" a kernel, we're creating:

.IP "1." 4
.B "The Foundation Canvas"
.br
The basic memory management and hardware abstraction that everything else 
builds upon

.IP "2." 4  
.B "The Color Palette"
.br
The system calls and interfaces that programs use to paint their functionality

.IP "3." 4
.B "The Composition Rules"
.br
The scheduling, process management, and resource allocation that keeps 
everything harmonious

.IP "4." 4
.B "The Frame"
.br
The security and isolation mechanisms that contain each program's artwork

.SH
Drawing Techniques: Plan 9's Kernel Philosophy
.PP
Plan 9's kernel drawing technique is unique. Instead of one monolithic artwork, 
it creates a series of connected sketches:

.IP \(bu 3
.B "Everything is a File"
.br
Like using the same brush stroke technique throughout a painting, Plan 9 uses 
the same file interface for everything - devices, networks, processes

.IP \(bu
.B "Distributed by Design"
.br
Like a mural spread across multiple walls, Plan 9 kernels can spread their 
functionality across multiple machines seamlessly

.IP \(bu
.B "9P Protocol"
.br
The "drawing language" that allows different parts of the system to communicate, 
like artists sharing techniques

.SH
The Drawing Process: How Drawkern Works
.PP
Imagine you could draw a kernel the same way you draw a terminal. The process 
would look like this:

.DS
drawkern -m memory.conf -d devices.conf -n network.conf
.DE

.PP
This hypothetical command would:

.IP "1." 4
.B "Prepare the Canvas" 
.br
Set up the memory management subsystem based on memory.conf

.IP "2." 4
.B "Add the Base Colors"
.br
Initialize device drivers from devices.conf  

.IP "3." 4
.B "Connect the Composition"
.br
Establish networking based on network.conf

.IP "4." 4
.B "Bring the Artwork to Life"
.br
Start the scheduler and begin running the complete system

.SH
Kernel Components as Art Elements
.PP
Just as an artist works with different materials, a Plan 9 kernel is composed 
of distinct elements:

.TS
center box;
c | c | c
l | l | l.
Art Element	Kernel Component	Purpose
_
Canvas	Memory Manager	Foundation for everything
Brushes	Device Drivers	Tools for interaction  
Palette	System Calls	Available functions
Composition	Scheduler	Timing and coordination
Frame	Security Model	Boundaries and protection
Signature	Process Table	Identity and ownership
.TE

.SH
Understanding Kernel Drawing Through Code
.PP
Let's look at how Plan 9's kernel initialization resembles an artist preparing 
their studio:

.DS
/* Preparing the canvas - memory initialization */
meminit();          // Stretch and prepare the canvas

/* Setting up brushes - device initialization */  
devinit();          // Arrange all the drawing tools

/* Mixing the palette - system call setup */
syscallinit();      // Prepare the available colors/functions

/* Beginning the artwork - process initialization */  
procinit();         // Start creating the living artwork
.DE

.PP
Each function call is like a deliberate brushstroke, building up the complete 
system one layer at a time.

.SH
The Living Kernel Artwork
.PP
Once drawn into existence, a Plan 9 kernel becomes a living, breathing artwork 
that:

.IP \(bu 3
.B "Responds to Touch"
- Programs can interact with it through the elegant file interface
.IP \(bu
.B "Grows and Adapts"
- New devices and services can be added dynamically
.IP \(bu  
.B "Maintains Harmony"
- The scheduler ensures all programs get their fair share of resources
.IP \(bu
.B "Preserves Itself"
- Security mechanisms protect the integrity of the artwork

.SH
From Drawkern to Ecosystem
.PP
Understanding kernels as drawn artworks leads us naturally to our next concept: 
kernels as seeds. Just as an artist's masterpiece can inspire other works, a 
well-drawn kernel can grow into an entire computing ecosystem.

.PP
The kernel you've drawn becomes the seed from which applications, services, and 
entire distributed systems can grow - each one carrying the elegant design 
principles of the original kernel artwork.

.SH
Practical Exercise: Exploring a "Drawn" Kernel
.PP
To see drawkern principles in action, try this exploration of a running Plan 9 
system:

.DS
ls /proc        # See the living processes (ongoing artworks)
cat /dev/swap   # View memory management (canvas status)  
ls /net         # Explore network interfaces (communication brushes)
cat /dev/sysctl # See system parameters (artistic settings)
.DE

.PP
Each of these commands reveals a different aspect of the "drawn" kernel - the 
living system that was painted into existence using the same principles as 
drawterm, but applied to create the system itself rather than just a window 
into it.

.SH
Key Concepts to Remember
.DS
Drawterm = Drawing a window into an existing system
Drawkern = Drawing the system itself into existence  
Kernel   = A living artwork composed of elegant components
Drawing  = The process of initialization and system creation
Canvas   = Memory management foundation
Brushes  = Device drivers and interfaces
Palette  = Available system calls and functions
.DE