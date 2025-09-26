.HTML "Drawing a Terminal: A Journey Through Remote Lands"
.TL
Drawing a Terminal
.br
A Beginner's Journey Through Remote Lands
.AU
Plan 9 Tutorial Team
.sp
tutorials@plan9.foundation
.AB
Imagine you're an artist with a magical paintbrush that can paint not just pictures,
but entire windows into distant worlds. This is the essence of "drawterm" - 
literally "drawing a terminal" that connects you to faraway Plan 9 systems.
Just as an artist sketches on canvas to bring imagination to life, drawterm
sketches a terminal window that brings distant computers to life on your screen.
.AE

.SH
What Does It Mean to "Draw" a Terminal?
.PP
When we say "draw" a terminal, think of it like this:
.IP \(bu 3
.B "The Canvas"
- Your local computer screen is like a blank canvas
.IP \(bu
.B "The Paintbrush" 
- The drawterm program is your magical paintbrush
.IP \(bu
.B "The Subject"
- The distant Plan 9 system is what you're painting a picture of
.IP \(bu
.B "The Painting"
- The terminal window that appears is your masterpiece - a living window into another world

.PP
Just as a landscape painter captures a distant mountain on canvas, drawterm captures
a distant computer system in a terminal window. But this is no static painting - 
it's alive! You can interact with it, run programs on it, and explore it as if 
you were actually there.

.SH
The Magic Behind the Canvas
.PP
When you run drawterm, several magical things happen:

.IP "1." 4
.B "Preparation of the Canvas"
.br
Your local system prepares a drawing surface (the terminal window)

.IP "2." 4
.B "Establishing the Connection"
.br
Like a telephone line to a distant land, drawterm opens a connection to the 
remote Plan 9 system

.IP "3." 4
.B "The Drawing Begins"
.br
Characters, colors, and graphics from the remote system are "drawn" onto your 
local canvas in real-time

.IP "4." 4
.B "Interactive Magic"
.br
Your keystrokes and mouse movements are sent back to the distant land, making 
the painting come alive

.SH
Your First Drawing Session
.PP
Let's create your first drawing! To start drawterm, you typically run:
.DS
drawterm -a auth.server.com -c cpu.server.com
.DE

This command tells your magical paintbrush:
.IP \(bu 3
.B "-a auth.server.com"
- Ask this server to verify you're allowed to paint
.IP \(bu
.B "-c cpu.server.com" 
- Draw a connection to this distant computer

.PP
Once connected, you'll see a terminal window appear - your first successful 
"drawing" of a remote terminal! The cursor blinking in that window is like 
the artist's signature, indicating you're now connected to a living, breathing 
system in another location.

.SH
Understanding the Drawing Process
.PP
The beautiful thing about drawterm is that it uses Plan 9's elegant graphics 
system under the hood. Every character you see, every color change, every 
piece of text is being "drawn" using the same fundamental graphics primitives 
that Plan 9 uses for all its visual elements.

.PP
This is why we call it "drawterm" rather than just "terminal" - because it's 
literally drawing the terminal onto your screen, pixel by pixel, using Plan 9's 
sophisticated graphics drawing system.

.SH
The Artist's Tools
.PP
As you become more comfortable with drawing terminals, you'll discover that 
drawterm gives you access to a full palette of tools:

.IP \(bu 3
.B "Text Tools"
- Multiple fonts and text rendering capabilities
.IP \(bu
.B "Color Palette"
- Full color support for a rich visual experience  
.IP \(bu
.B "Window Management"
- Resize, move, and manage your terminal canvas
.IP \(bu
.B "Graphics Support"
- Not just text - Plan 9 can draw actual graphics in terminals!

.SH
Next Steps: Beyond Basic Drawing
.PP
Now that you understand the artistic metaphor behind drawterm, you're ready to 
explore more advanced concepts:

.IP \(bu 3
How the "drawing" actually works at a technical level
.IP \(bu
Creating multiple canvases (multiple terminal windows)
.IP \(bu
Understanding the communication protocol between artist and subject
.IP \(bu
Exploring Plan 9's unique approach to distributed computing

.PP
Remember: every time you use drawterm, you're not just opening a terminal - 
you're creating a living artwork that bridges the gap between your local world 
and a distant Plan 9 system. Happy drawing!

.SH
Key Concepts to Remember
.DS
Canvas     = Your local screen/window
Paintbrush = The drawterm program  
Subject    = The remote Plan 9 system
Painting   = The terminal window that appears
Artist     = You, the user exploring distant lands
.DE