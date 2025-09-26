.HTML "Plan 9 Documentation and Fonts: A Beginner's Guide"
.TL
Plan 9 Documentation and Fonts
.br
A Beginner's Guide to the True Power of the P9 System
.AU
Plan 9 Documentation Team
.sp
docs@plan9.bell-labs.com
.AB
This guide transforms the often cryptic and esoteric world of Plan 9
documentation into a clear, accessible tutorial. Whether you're a
stumbling novice or seasoned veteran, this guide will introduce you
to the true power of the Plan 9 system, including the mysterious
"font" and "subfont" system that lies at the heart of Plan 9's
beautiful typography.

The wave of democratization is at hand - it's time to make Plan 9
documentation accessible to everyone!
.AE
.SH
Welcome to Plan 9 Documentation
.PP
If you've ever looked at Plan 9 man pages and felt like you were
deciphering ancient hieroglyphics, you're not alone. This guide
will transform your understanding and show you that Plan 9's
documentation system is actually elegant and powerful - once you
know how to read it.
.PP
.B "What Makes Plan 9 Documentation Special?"
.PP
Plan 9 documentation is built on several key principles:
.IP \(bu 3
.B Consistency
- All documentation follows the same format and structure
.IP \(bu
.B Completeness
- Everything is documented, from basic commands to internal APIs
.IP \(bu
.B Integration
- Documentation is tightly integrated with the system itself
.IP \(bu
.B Unicode Support
- Full international character support throughout
.SH
Understanding Man Pages
.PP
Man pages in Plan 9 are organized into sections:
.TP
.B "Section 1"
User commands (like 
.IR ls ,
.IR cat ,
.IR troff )
.TP
.B "Section 2"
System calls and library functions
.TP
.B "Section 3"
File formats and protocols
.TP
.B "Section 4"
Device drivers
.TP
.B "Section 5"
Database formats
.TP
.B "Section 6"
File formats and data structures
.TP
.B "Section 7"
Miscellaneous
.TP
.B "Section 8"  
System administration
.PP
.B "Reading a Man Page"
.PP
Every man page follows the same structure:
.IP "NAME" 10
What the command or function is called
.IP "SYNOPSIS"
How to use it (syntax and options)
.IP "DESCRIPTION"
What it does and how it works
.IP "EXAMPLES"
Practical usage examples (when provided)
.IP "FILES"
Related files and directories
.IP "SOURCE"
Where to find the source code
.IP "SEE ALSO"
Related commands and documentation
.IP "DIAGNOSTICS"
Error messages and troubleshooting
.PP
.B "Your First Man Page"
.PP
Let's start with something simple. Try:
.P1
man cat
.P2
.PP
This shows you the manual for the 
.I cat
command. Notice how it follows the standard structure we just described.
.SH
The Typography System: Fonts and Subfonts Demystified
.PP
One of Plan 9's greatest strengths is its typography system. Understanding
fonts and subfonts is key to creating beautiful documents and understanding
how Plan 9 handles text.
.PP
.B "The Big Picture"
.PP
Plan 9's font system works like this:
.IP "1." 4
.B Characters
are organized into
.B subfonts
based on their Unicode ranges
.IP "2."
.B Subfonts
contain the actual bitmap images of characters
.IP "3."
.B Fonts
are collections of subfonts that work together
.IP "4."
.B Documents
reference fonts, which automatically load the right subfonts
.PP
Think of it like a library:
.IP \(bu 3
A 
.B font
is like the library's catalog - it tells you where to find things
.IP \(bu
A
.B subfont
is like a shelf of books - it contains the actual content
.IP \(bu
.B Characters
are like individual books on the shelf
.PP
.B "Why This System?"
.PP
This design allows Plan 9 to:
.IP \(bu 3
Handle huge character sets like Unicode efficiently
.IP \(bu
Load only the characters you actually use
.IP \(bu
Mix different scripts (Latin, Greek, Japanese, etc.) in one document
.IP \(bu
Share common character ranges between fonts
.PP
.B "Fonts You'll Encounter"
.PP
Plan 9 comes with several font families:
.TP
.B LucidaSans
Clean, readable sans-serif fonts (default for most uses)
.TP
.B Times
Traditional serif fonts for formal documents
.TP
.B LucidaCW
Monospace fonts for code and terminal output
.TP
.B Pelm
Specialized fonts including international character support
.PP
Each family includes variations:
.IP \(bu 3
.B Roman
(normal weight)
.IP \(bu
.B Italic
(slanted)
.IP \(bu
.B Bold
(heavy weight)
.IP \(bu
.B Bold Italic
(heavy and slanted)
.SH
Creating Your First Document
.PP
Let's create a simple document to see the typography system in action.
.PP
.B "Step 1: Create a Simple Document"
.PP
Create a file called 
.CW hello.ms
with this content:
.P1
\&.TL
My First Plan 9 Document
\&.AU  
Your Name
\&.PP
This is a paragraph in the default font.
\&.PP
\\efIThis paragraph is in italic.\\efP
\&.PP
\\efBThis paragraph is in bold.\\efP
\&.PP
\\ef(CWThis paragraph is in monospace.\\efP
.P2
.PP
.B "Step 2: Process the Document"
.PP
Now format it with troff:
.P1
troff -ms hello.ms | dpost > hello.ps
.P2
.PP
This creates a PostScript file you can view or print.
.PP
.B "Step 3: Preview on Screen"
.PP
To see what it looks like without printing:
.P1
troff -ms -a hello.ms
.P2
.PP
The 
.CW -a
option produces ASCII output you can read directly.
.PP
.B "What Just Happened?"
.PP
When you ran troff:
.IP "1." 4
It read your document and the 
.CW ms
macro package
.IP "2."
It determined what fonts were needed
.IP "3."
It loaded the appropriate subfont files for each character
.IP "4."
It calculated spacing and positioning
.IP "5."
It output formatting commands for the PostScript processor
.SH
Understanding Font Selection
.PP
Plan 9 gives you fine control over fonts. Here's how font selection works:
.PP
.B "Default Font Mounting"
.PP
When troff starts, it "mounts" fonts on positions 1-4:
.IP "Position 1" 10
Roman (normal) font
.IP "Position 2"
Italic font
.IP "Position 3"
Bold font
.IP "Position 4"
Bold italic font
.PP
.B "Changing Fonts"
.PP
You can change fonts in several ways:
.TP
.B "Font Positions"
Use 
.CW \ef1 ,
.CW \ef2 ,
.CW \ef3 ,
.CW \ef4
for the mounted fonts
.TP
.B "Font Names"
Use 
.CW \efR ,
.CW \efI ,
.CW \efB
for Roman, Italic, Bold
.TP
.B "Two-Character Names"
Use 
.CW \ef(CW
for Constant Width, 
.CW \ef(BI
for Bold Italic
.TP
.B "Full Names"
Use 
.CW \ef(Times-Roman
for specific font files
.PP
.B "Examples of Font Changes"
.PP
.P1
Normal text
\\efIitalic text\\efP
\\efBbold text\\efP  
\\ef(CWmonospace text\\efP
\\ef(BIbold italic text\\efP
.P2
.SH
Working with International Text
.PP
One of Plan 9's greatest strengths is Unicode support. You can include
text in any language directly in your documents.
.PP
.B "Unicode Character Entry"
.PP
You can enter Unicode characters in several ways:
.TP
.B "Direct Entry"
If your editor supports it, type characters directly: café, naïve
.TP
.B "Numeric Entry"
Use 
.CW \eN'number'
where number is the Unicode code point
.TP
.B "Named Characters"
Use traditional troff names like 
.CW \e(co
for ©
.PP
.B "International Text Example"
.PP
Create a file called 
.CW international.ms :
.P1
\&.TL
International Typography Example
\&.PP
English: Hello, World!
\&.PP
French: Bonjour, le monde!
\&.PP
German: Hallo, Welt!
\&.PP
Greek: Καλημέρα κόσμε!
\&.PP
Japanese: こんにちは 世界！
\&.PP
Mathematical: ∫₀^∞ e^(-x²) dx = √π/2
.P2
.PP
Process it with:
.P1
troff -ms international.ms | dpost > international.ps
.P2
.SH
Common Tasks and Solutions
.PP
Here are solutions to common documentation tasks:
.PP
.B "Creating Headers and Footers"
.PP
.P1
\&.de HD    \\e" Header macro
\&.tl ''Document Title''
\&.sp
\&..
\&.de FO    \\e" Footer macro  
\&.bp
\&.tl ''%''
\&..
\&.wh 0 HD   \\e" Header at top
\&.wh -1i FO \\e" Footer 1 inch from bottom
.P2
.PP
.B "Two-Column Layout"
.PP
.P1
\&.2C        \\e" Start two-column mode
Text flows in two columns automatically.
\&.1C        \\e" Return to single column
.P2
.PP
.B "Including Code"
.PP
.P1
\&.CW       \\e" Change to constant width font
#include <stdio.h>
int main() {
    printf("Hello, World!\\n");
    return 0;
}
\&.R        \\e" Return to Roman font
.P2
.PP
.B "Mathematical Equations"
.PP
Use the 
.I eqn
preprocessor:
.P1
\&.EQ
x = {-b +- sqrt{b sup 2 - 4ac}} over {2a}
\&.EN
.P2
.PP
Process with:
.P1
eqn file.ms | troff -ms | dpost > output.ps
.P2
.SH
Troubleshooting Common Problems
.PP
.B "Font Not Found Errors"
.PP
If you get font-related errors:
.IP "1." 4
Check that font files exist in 
.CW /lib/font/bit/
.IP "2." 
Verify font descriptions in 
.CW /sys/lib/troff/font/devutf/
.IP "3."
Make sure you're using the correct font names
.IP "4."
Try the 
.CW -F
option to specify a different font directory
.PP
.B "Character Display Issues"
.PP
If characters appear as boxes or squares:
.IP "1." 4
The character isn't in the current font - try a different font
.IP "2."
The Unicode code point might be wrong - check the character code
.IP "3."
The subfont file might be missing - check 
.CW /lib/font/bit/
.PP
.B "Spacing Problems"
.PP
If text spacing looks wrong:
.IP "1." 4
Check that font metrics match the actual fonts
.IP "2."
Verify the 
.CW unitwidth
setting in the device description
.IP "3."
Make sure you're using matching font families
.PP
.B "PostScript Errors"
.PP
If 
.I dpost
fails:
.IP "1." 4
Try the 
.CW -Tpost
device instead of 
.CW -Tutf
.IP "2."
Check that custom fonts are properly installed
.IP "3."
Verify your PostScript interpreter supports the fonts
.SH
Where to Go From Here
.PP
Now that you understand the basics, here are your next steps:
.PP
.B "Essential Reading"
.PP
.IP \(bu 3
.IR troff (1)
- The main typesetting command
.IP \(bu
.IR ms (6)
- The manuscript macro package
.IP \(bu
.IR font (6)
- Font file formats (now much more readable!)
.IP \(bu
.IR subfont (2)
- Subfont programming interface
.PP
.B "Practice Documents"
.PP
Try creating these types of documents:
.IP \(bu 3
A simple letter using 
.CW -ms
macros
.IP \(bu
A technical report with equations using 
.I eqn
.IP \(bu
A manual page using 
.CW -man
macros
.IP \(bu
A presentation using 
.I pic
for diagrams
.PP
.B "Advanced Topics"
.PP
Once you're comfortable with basics:
.IP \(bu 3
Learn 
.IR pic (1)
for drawing diagrams
.IP \(bu
Master 
.IR tbl (1)
for complex tables
.IP \(bu
Explore 
.IR grap (1)
for graphs and charts
.IP \(bu
Study the source code in 
.CW /sys/src/cmd/troff/
.PP
.B "Contributing"
.PP
The Plan 9 documentation is a living system. You can:
.IP \(bu 3
Report unclear or missing documentation
.IP \(bu
Submit improvements to existing man pages
.IP \(bu
Create new tutorial documents like this one
.IP \(bu
Help translate documentation to other languages
.SH
Conclusion
.PP
Congratulations! You've taken your first steps into the powerful world
of Plan 9 documentation and typography. What once seemed like cryptic
hieroglyphics should now make sense as a coherent, elegant system.
.PP
The Plan 9 way is about understanding the underlying principles and
then applying them consistently. The font system, the documentation
format, and the commands all follow this philosophy.
.PP
Remember: every expert was once a beginner. Don't be afraid to experiment,
read the source code, and ask questions. The Plan 9 community values
learning and knowledge sharing.
.PP
Welcome to the true power of the Plan 9 system. The wave of democratization
has begun - now go forth and create beautiful, accessible documentation!
.PP
.I "Happy typesetting!"