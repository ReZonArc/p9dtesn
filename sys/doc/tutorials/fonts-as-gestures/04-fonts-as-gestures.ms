.HTML "Fonts as Gestures: The Language of Dynamic Typography"
.TL
Fonts as Gestures
.br
Understanding Typography as a Language of Dynamic Expression
.AU
Plan 9 Tutorial Team
.sp
tutorials@plan9.foundation
.AB
Moving beyond viewing fonts as fixed, static shapes, we explore the revolutionary 
concept of fonts as gestures - dynamic, expressive movements that convey meaning 
through motion and intention rather than rigid positioning. In Plan 9's advanced 
typography system, each character is not a fixed bitmap but a living gesture 
that adapts to context, scale, and purpose.
.AE

.SH
From Static Shapes to Living Gestures
.PP
Traditional typography treats characters like stamps - fixed shapes pressed 
onto paper or pixels. Plan 9's approach is radically different:

.TS
center box;
c | c
l | l.
Traditional Fonts	Plan 9 Font Gestures
_
Fixed bitmaps	Dynamic vector descriptions
Single size	Infinite scalability  
Static positioning	Contextual adaptation
Mechanical repetition	Expressive variation
Pixel-locked	Resolution independent
.TE

.SH
The Gesture Metaphor: How Characters Move and Express
.PP
Think of writing with a calligraphy brush. Each stroke is a gesture - it has:

.IP \(bu 3
.B "Intent"
- The meaning you want to convey
.IP \(bu
.B "Motion"  
- The path the brush takes through space
.IP \(bu
.B "Pressure"
- How firmly you press (line weight)
.IP \(bu
.B "Speed"
- How quickly you move (affects character flow)
.IP \(bu
.B "Context"
- How this stroke relates to others around it

.PP
Plan 9 fonts encode these same gestural qualities digitally.

.SH
Deconstructing a Gestural Character
.PP
Let's explore how the letter "A" becomes a gesture in Plan 9:

.DS
struct FChar {
    int x;           // Starting position (where gesture begins)
    uchar top;       // Ascent (upward gesture extent)  
    uchar bottom;    // Descent (downward gesture extent)
    uchar left;      // Left bearing (gesture preparation)
    uchar width;     // Advance width (gesture completion)
    ushort mwidth;   // Metric width (gesture spacing)
};
.DE

.PP
Each field captures a different aspect of the gestural movement:

.IP \(bu 3
.B "x, left, width"
- The horizontal dance of the gesture
.IP \(bu
.B "top, bottom"  
- The vertical expression range
.IP \(bu
.B "mwidth"
- How the gesture flows into the next

.SH
Gesture Languages: Different Font Styles as Dialects
.PP
Just as human cultures have different gestural languages, Plan 9 supports 
multiple "gesture dialects" for different purposes:

.IP \(bu 3
.B "Terminal Gestures"
.br
Sharp, precise movements for code and system interaction
.DS
/lib/font/bit/fixed     # Mechanical, consistent gestures
/lib/font/bit/courier   # Typewriter-like rhythmic gestures  
.DE

.IP \(bu
.B "Display Gestures"
.br
Flowing, expressive movements for documents and interfaces
.DS
/lib/font/bit/times     # Classical, formal gestures
/lib/font/bit/helvetica # Clean, modern gestures
.DE

.IP \(bu
.B "Artistic Gestures"
.br
Creative, unique movements for special purposes
.DS
/lib/font/bit/script    # Handwriting-like flowing gestures
/lib/font/bit/gothic    # Medieval, ornate gestures
.DE

.SH
The Gesture Rendering Engine
.PP
Plan 9's font rendering system is essentially a gesture interpreter. Here's 
how it translates gesture descriptions into visible characters:

.DS
/* The gesture interpretation process */
Subfont *getsubfont(Display *d, char *name) {
    // Load the gesture vocabulary
}

Point string(Image *dst, Point pt, Font *f, char *s) {
    // Perform the gestural sequence
    for each character in string:
        interpret_gesture(character)
        blend_with_context(previous, current, next)
        render_to_canvas(dst, gesture_result)
        advance_position()
}
.DE

.SH
Dynamic Resolution: Gestures That Scale
.PP
The magic of gestural fonts is their ability to adapt to any scale while 
maintaining their essential character:

.IP "1." 4
.B "Micro Gestures (8-12pt)"
.br
Simplified, essential movements - only the core gesture elements
.DS
Small text requires economical gestures - each stroke must count
.DE

.IP "2." 4
.B "Display Gestures (14-24pt)"
.br
Full expression - all gestural nuances visible
.DS
Medium sizes allow complete gestural vocabulary
.DE

.IP "3." 4
.B "Poster Gestures (36pt+)"
.br
Enhanced details, subtle variations become prominent features
.DS
Large sizes reveal the artistry in each gesture
.DE

.SH
Contextual Gesture Adaptation
.PP
Advanced gestural fonts can modify their expression based on context:

.IP \(bu 3
.B "Positional Awareness"
.br
Characters adjust their gestures based on neighbors
.DS
"fi" ligature - two gestures blend into one flowing movement
"qu" combination - the 'u' gesture adapts to follow 'q'
.DE

.IP \(bu
.B "Semantic Sensitivity"
.br
Gestures can vary based on meaning
.DS
Code: sharp, precise gestures for clarity
Prose: flowing, readable gestures for comfort  
Headers: bold, commanding gestures for attention
.DE

.SH
Building Your Own Gesture Vocabulary
.PP
Creating custom fonts in Plan 9 means defining new gestural vocabularies:

.DS
# Design process for gestural fonts:

1. Define the gesture philosophy
   - What emotion/purpose should these gestures convey?
   
2. Create the base movements  
   - Design core strokes that embody your philosophy
   
3. Build the character set
   - Apply your stroke philosophy to each letter
   
4. Test gestural flow
   - Ensure gestures work together harmoniously
   
5. Optimize for scales
   - Verify gestures work at different sizes
.DE

.SH
The Orchestra of Gestures: Typography in Motion
.PP
When you read text rendered with Plan 9's gestural fonts, you're not just 
seeing static shapes - you're witnessing a performance:

.IP \(bu 3
.B "Each Character"
- A solo performance, expressing its individual gesture
.IP \(bu
.B "Each Word"
- A small ensemble, gestures harmonizing together
.IP \(bu
.B "Each Line"  
- A full orchestra section, creating rhythmic flow
.IP \(bu
.B "Each Page"
- A complete symphony, conveying complex meaning through gestural composition

.SH
Practical Gestural Typography
.PP
To experience gestural fonts in action:

.DS
# Explore different gesture vocabularies
page /lib/font/bit/*/    # See available gesture sets

# Watch gestures adapt to scale  
acme -f /lib/font/bit/times/times.8.font &
acme -f /lib/font/bit/times/times.16.font &

# Compare gestural languages
stats -f /lib/font/bit/courier/* 
stats -f /lib/font/bit/times/*
.DE

.SH
The Future: Animated Gestures
.PP
Plan 9's gestural approach opens possibilities for truly dynamic typography:

.IP \(bu 3
.B "Temporal Gestures"
- Characters that reveal themselves over time
.IP \(bu
.B "Interactive Gestures"  
- Typography that responds to user interaction
.IP \(bu
.B "Contextual Animation"
- Gestures that adapt in real-time to content meaning
.IP \(bu
.B "Collaborative Gestures"
- Multiple users' gestures blending in shared documents

.SH
From Gestures to Graphics
.PP
Understanding fonts as gestures naturally leads us to vector graphics - where 
the same gestural principles apply to all visual elements, not just text. 
Every line, curve, and shape becomes a gesture with intent, motion, and 
expressive capability.

.PP
The transition from gestural typography to gestural graphics is seamless in 
Plan 9's unified approach to visual expression.

.SH
Key Concepts to Remember
.DS
Font = Vocabulary of gestural movements
Character = Individual gesture with intent and motion  
Rendering = Interpreting gestures into visible form
Scaling = Adapting gestures to different sizes
Context = How gestures influence each other
Flow = The rhythm and harmony of gestural sequences
Expression = The emotional/semantic content of gestures
.DE