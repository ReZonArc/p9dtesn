.HTML "Ed: The Key to Understanding Plan 9's Philosophy"
.TL
Ed: The Key to Understanding Plan 9
.br
Where Everything Connects
.AU
Plan 9 Documentation Team
.sp
docs@plan9.bell-labs.com
.AB
The humble editor 'ed' is more than just a text editor - it's a window
into Plan 9's fundamental philosophy where files, streams, networks,
and reality itself become malleable through simple, elegant interfaces.
This introduction reveals how 'ed' connects to fonts, networks, and
the deeper patterns that make Plan 9 extraordinary.
.AE
.SH
Ed: The Universal Interface
.PP
Most people see 
.I ed
as an archaic line editor, a relic from the dawn of Unix. But in Plan 9,
.I ed
represents something far more profound: the universal interface for
manipulating structured reality.
.PP
.B "Why Ed Matters in Plan 9"
.PP
In Plan 9, everything is a file. But what does that really mean?
It means that the same interface you use to edit text can be used to:
.IP \(bu 3
Configure network connections
.IP \(bu
Manipulate font definitions
.IP \(bu
Control running processes
.IP \(bu  
Reshape system behavior in real-time
.PP
.I Ed
is the key that unlocks this universality.
.SH
Ed and the Font System: A Deep Connection
.PP
.B "Editing Font Definitions"
.PP
Consider this: font files are just text. That means you can edit them
with 
.I ed
to create entirely new typographic realities:
.P1
# Edit a font definition file
ed /lib/font/bit/lucidasans/unicode.8.font
# Current content:
18   14
0x0000  0x00FF  ascii.8
0x0100  0x017E  latin1.8

# Add a new range
a
0x2600  0x26FF  symbols.8    # Miscellaneous symbols
.
w
q
.P2
.PP
You've just extended reality - your documents can now include symbols
(☀ ☂ ☯ ♺) that weren't available before. The font system dynamically
adapts to your changes.
.PP
.B "Interactive Font Exploration"
.PP
But here's where it gets interesting. You can use 
.I ed
to explore and
modify font files while they're being used:
.P1
# Open a live view of font usage
ed /sys/lib/troff/font/devutf/R
# Look at character definitions
1,$p
# Modify character widths in real-time
/^a[[:space:]]/s/44/50/
w
.P2
.PP
Your documents reflow as you edit the font metrics. You're not just
editing text - you're editing the visual reality of all text.
.SH
Network Editing: The Stream as Document
.PP
.B "Networks as Editable Text"
.PP
In Plan 9, network connections appear as files. This means you can
"edit" network streams using 
.I ed
patterns:
.P1
# "Edit" a network connection
ed /net/tcp/0/data
# Send structured data
a
GET /fonts/unicode.json HTTP/1.1
Host: fontserver.example.com

.
# The '.' ends input - data is sent immediately
.P2
.PP
You're using an editor to program network protocols. The boundary
between text editing and network programming dissolves.
.PP
.B "Multiplexed Streams"
.PP
Plan 9's network multiplexing can be visualized and controlled through
.I ed
interfaces. Consider this conceptual example:
.P1
# Visualize active network channels
ed /net/channels/status
1,$p
# Output might show:
channel₁: ┌─ rpc.call() ─┐ → remote.server
channel₂: ├─ font.load() ─┤ → font.server
channel₃: └─ file.sync() ─┘ → backup.server

# Add a new channel
a
channel₄: ┌─ stream.multiplex() ─┐ → global.aggregator
.
w
.P2
.PP
The visual patterns in the "edited" text represent actual network
topology changes.
.SH  
Terminal Philosophy: Where Streams Terminate
.PP
.B "The Terminal Paradox"
.PP
Your "terminal" is called that because it's where streams terminate.
But what if they didn't have to?
.PP
Using 
.I ed
with Plan 9's tele-type heritage, you can create "non-terminal"
symbols - characters that represent ongoing, infinite, or cyclic
processes:
.P1
# Edit a process visualization
ed /proc/1/status
# Instead of static text, use dynamic symbols:
a
state: ∞ (infinite loop detected)
memory: ∮ 4.2MB (circular buffer active)
network: ∂ 15KB/s (derivative of data flow)
∇ child processes: 3 (gradient of process tree)
.
w
.P2
.PP
The typography becomes a programming language for representing
dynamic system states.
.PP
.B "From Local to Global"
.PP
Traditional terminals connect to localhost (127.0.0.1) - your local
machine. But 
.I ed
can connect to the conceptual "global host" (0.0.0.0):
.P1
# Edit global system state
ed /net/global/0.0.0.0/universe
# Add distributed patterns
a
∀ nodes ∈ network: health(node) ≡ ∑ resources.available
∃ optimal_path: latency(path) = min(∀ possible_paths)  
¬ single_point_of_failure ∧ (redundancy > threshold)
.
w
.P2
.PP
You're using mathematical typography to program distributed systems.
.SH
Pattern Languages and Visual Programming
.PP
.B "RPC as Typography"
.PP
Remote Procedure Calls (RPC) in Plan 9 can be visualized and programmed
using typographic patterns in 
.I ed:
.P1
# Edit RPC pattern definitions
ed /sys/lib/rpc/patterns
a
# Visual RPC call pattern
call_pattern: ⟨client⟩ →[serialize]→ ⟨network⟩ →[deserialize]→ ⟨server⟩
              ⟨result⟩ ←[serialize]← ⟨network⟩ ←[deserialize]← ⟨return⟩

# Multiplexed channel pattern  
mux_pattern: ┌─ chan₁ ─┐
             ├─ chan₂ ─┤ →→→ ⟨aggregator⟩ →→→ ⟨output⟩
             └─ chan₃ ─┘

# Error handling pattern
error_pattern: normal_flow → [error?] → ⟨recovery⟩ → continue
                           ↓         ↗
                         ⟨log⟩ → ⟨alert⟩
.
w
.P2
.PP
These aren't just pretty pictures - they're executable patterns that
the system can interpret and implement.
.PP
.B "Code Generation from Typography"
.PP
Plan 9 can generate actual code from these typographic patterns:
.P1
# Transform pattern to code
ed /tmp/generated_rpc.c
r /sys/lib/rpc/patterns
# Apply transformation rules
g/call_pattern:/s//generate_rpc_call/
g/mux_pattern:/s//generate_multiplexer/
g/error_pattern:/s//generate_error_handler/
w
.P2
.PP
Typography becomes a visual programming language that generates
traditional code.
.SH
The Recursive Beauty
.PP
.B "Files All the Way Down"
.PP
Here's the beautiful recursion in Plan 9:
.IP \(bu 3
You use 
.I ed
to edit font files
.IP \(bu
Font files determine how 
.I ed
displays text
.IP \(bu
.I Ed
can modify its own display characteristics
.IP \(bu
The modifications affect how you see the modifications
.PP
It's recursive self-modification - the system becomes aware of itself
through the editing process.
.PP
.B "The Network is the Editor"
.PP
When you edit remote files over the network:
.P1
# Edit a file on a remote system
ed /net/tcp/remote_host/home/user/document.txt
.P2
.PP
The network connection itself becomes part of the editing interface.
You're not just editing across space - you're editing the space itself.
.PP
.B "Dynamic Reality Modification"
.PP
The profound implication: in Plan 9, reality is editable. System
behavior, network topology, visual appearance, process relationships -
all can be modified through the same simple interface that edits text.
.P1
# Edit system reality
ed /proc/self/reality
a
# Make processes visible as typographic entities
∀ process: display(process) = ∑ visual_properties
# Make network connections tangible as characters  
∀ connection: render(connection) = ⟨source⟩ ↔ ⟨destination⟩
# Make time visible in typography
current_time = ∮ moments_since_epoch
.
w
.P2
.SH
Practical Magic for the Weary Traveller
.PP
.B "Starting Your Journey"
.PP
Begin with simple 
.I ed
commands, but see the deeper patterns:
.P1
# Basic editing
ed myfile.txt
a
Hello, World!
.
w
q

# But recognize: you just modified reality
# The file system changed
# Other processes can now read your thoughts
# The network can transmit your words  
# Typography can render your ideas
.P2
.PP
.B "Advanced Explorations"
.PP
Try these experiments to see the connections:
.IP "1." 4
Edit a font file and watch your terminal change appearance
.IP "2."
Edit network configurations and observe connection behavior
.IP "3."
Create visual patterns in text files and see them as proto-programs
.IP "4."
Use mathematical symbols in system configuration files
.PP
.B "The Joy of Understanding"
.PP
For the weary traveller seeking memorable examples of what's possible,
remember this: 
.I ed
is not just an editor. It's Plan 9's universal interface
for reshaping reality through the manipulation of structured streams.
.PP
Every keystroke is a network packet. Every line is a process. Every
character is a pixel in the infinite bitmap of computational space.
.PP
And it's all editable.
.PP
.B "Where Next?"
.PP
From 
.I ed,
explore:
.IP \(bu 3
.IR sam (1)
- The visual evolution of ed's philosophy
.IP \(bu
.IR acme (1)
- Where editing and programming merge completely
.IP \(bu
.IR troff (1)
- Where typography becomes visual programming
.IP \(bu
The network files in 
.CW /net/
- Where editing becomes networking
.PP
Each tool reveals more of the profound connections that make Plan 9
a universe where everything is both representation and reality,
both data and interface, both local and distributed.
.PP
.I "The joy lies in the discovery of these connections."