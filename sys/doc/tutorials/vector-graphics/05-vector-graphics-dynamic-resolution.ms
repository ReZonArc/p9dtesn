.HTML "Vector Graphics: Quantized Routines of Applied Technique"
.TL
Vector Graphics and Dynamic Resolution
.br
Encoding Generative Techniques for Infinite Scalability
.AU
Plan 9 Tutorial Team
.sp
tutorials@plan9.foundation
.AB
Building on our understanding of fonts as gestures, we now explore how Plan 9's 
vector graphics system treats all visual elements as "quantized routines of 
applied technique" - repeatable sequences of drawing operations that encode 
generative methods rather than fixed pixels. Like a master craftsperson's 
documented techniques, vector graphics preserve the method rather than just 
the result.
.AE

.SH
From Pixels to Procedures: The Vector Revolution
.PP
Traditional computer graphics stores results - arrays of colored pixels. 
Vector graphics stores methods - sequences of drawing operations:

.TS
center box;
c | c  
l | l.
Raster (Pixel) Graphics	Vector Graphics
_
Stores final results	Stores creation methods
Fixed resolution	Infinite scalability
Large file sizes	Compact descriptions
Degrades when scaled	Improves when scaled
Static representation	Dynamic generation
Memory intensive	Computation intensive
.TE

.SH
Quantization: Breaking Art Into Reproducible Steps
.PP
"Quantization" in graphics means breaking down artistic techniques into 
discrete, measurable steps that can be precisely reproduced:

.IP \(bu 3
.B "Continuous Gesture"
.br
An artist draws a smooth curve with flowing hand motion

.IP \(bu
.B "Quantized Routine"
.br
The same curve becomes: "move to (10,20), curve to (30,5) via control points 
(15,10) and (25,8), end stroke"

.DS
/* Plan 9 vector graphics quantization */
typedef struct Point Point;
struct Point {
    int x, y;       // Quantized position coordinates
};

typedef struct Rectangle Rectangle;  
struct Rectangle {
    Point min, max; // Quantized boundary definition
};

/* A bezier curve - quantized artistic gesture */
void bezier(Image *dst, Point p0, Point p1, Point p2, Point p3) {
    // The quantized routine for reproducing a curved gesture
}
.DE

.SH
Applied Technique: The Artist's Method Encoded
.PP
Each vector operation encodes a specific artistic technique:

.IP "1." 4
.B "Line Drawing Technique"
.DS
line(dst, Pt(x1,y1), Pt(x2,y2), src, ZP, op);
// Technique: "Draw straight from point A to point B"
.DE

.IP "2." 4
.B "Area Filling Technique"  
.DS
draw(dst, rect, src, nil, ZP, op);
// Technique: "Fill this area with this pattern/color"
.DE

.IP "3." 4
.B "Blending Technique"
.DS
gendraw(dst, r, src, p0, mask, p1, op);
// Technique: "Combine two images using this method"
.DE

.IP "4." 4
.B "Transformation Technique"
.DS
// Rotation technique - encoded as matrix operations
Matrix m = rotmatrix(angle);
transform(image, m);
.DE

.SH
Build Sequences: Repeatable Artistic Processes
.PP
Complex graphics are built through sequences of quantized techniques, like 
following a master artist's step-by-step tutorial:

.DS
/* A "build sequence" for drawing a house icon */
Image* draw_house_icon(Display *d, int size) {
    Image *house = allocimage(d, Rect(0,0,size,size), RGB24, 0, DNofill);
    
    // Step 1: Foundation technique
    Rectangle base = Rect(size/4, 3*size/4, 3*size/4, size);
    draw(house, base, display->black, nil, ZP, S);
    
    // Step 2: Wall technique  
    Rectangle walls = Rect(size/4, size/2, 3*size/4, 3*size/4);
    draw(house, walls, display->white, nil, ZP, S);
    
    // Step 3: Roof technique
    Point roof[] = {Pt(size/4, size/2), Pt(size/2, size/4), 
                    Pt(3*size/4, size/2)};
    fillpoly(house, roof, 3, ~0, display->black, ZP, S);
    
    // Step 4: Door technique
    Rectangle door = Rect(size/2-size/16, 2*size/3, size/2+size/16, size);
    draw(house, door, display->black, nil, ZP, S);
    
    return house;
}
.DE

.PP
This "build sequence" can create a perfect house icon at any size - 16x16 
pixels for a small icon, or 1024x1024 pixels for a poster.

.SH
Dynamic Resolution: The Magic of Scalability
.PP
The true power of quantized routines becomes apparent with scaling:

.IP \(bu 3
.B "12px Icon"
.br
Basic shapes, minimal detail, optimized for clarity at tiny size

.IP \(bu
.B "64px Icon"  
.br
Full detail, all elements visible, balanced proportions

.IP \(bu
.B "256px Icon"
.br
Enhanced details, subtle gradients, artistic flourishes become visible

.IP \(bu
.B "1024px Poster"
.br
Maximum detail, textures, shadows - the routine generates appropriate 
complexity for the target resolution

.DS
/* The same routine adapts to different scales */
house_12px  = draw_house_icon(display, 12);   // Simplified execution
house_64px  = draw_house_icon(display, 64);   // Standard execution  
house_256px = draw_house_icon(display, 256);  // Enhanced execution
house_1024px = draw_house_icon(display, 1024); // Full detail execution
.DE

.SH
Generative Glyphs: Self-Creating Visual Elements
.PP
The most advanced application of quantized routines is generative glyphs - 
visual elements that create themselves through algorithmic processes:

.DS
/* A generative glyph for drawing trees */
Image* generate_tree(Display *d, int size, int seed, int season) {
    srand(seed);  // Quantized randomness - repeatable "creativity"
    
    Image *tree = allocimage(d, Rect(0,0,size,size), RGB24, 0, DNofill);
    
    // Recursive branching routine
    draw_branch(tree, Pt(size/2, size), size/3, PI/2, 0, season);
    
    return tree;
}

void draw_branch(Image *tree, Point start, int length, 
                 double angle, int depth, int season) {
    if (depth > 5 || length < 3) return;  // Quantized stopping condition
    
    // Calculate end point using quantized trigonometry
    Point end = Pt(start.x + length * cos(angle),
                   start.y - length * sin(angle));
    
    // Draw this branch segment
    line(tree, start, end, branch_color(season), nil, S);
    
    // Recursive sub-branches - quantized organic growth
    double branch_angle = (rand() % 60 - 30) * PI/180;  // ±30 degrees
    int new_length = length * 0.7;  // Quantized length reduction
    
    draw_branch(tree, end, new_length, angle + branch_angle, depth+1, season);
    draw_branch(tree, end, new_length, angle - branch_angle, depth+1, season);
}
.DE

.SH
The Plan 9 Graphics Pipeline: Technique Composition
.PP
Plan 9's graphics system composes techniques through a sophisticated pipeline:

.IP "1." 4
.B "Technique Definition"
.br
Basic drawing operations (line, fill, blend, transform)

.IP "2." 4  
.B "Routine Composition"
.br
Combining basic techniques into complex procedures

.IP "3." 4
.B "Build Sequence Execution"
.br
Running the composed routines to generate graphics

.IP "4." 4
.B "Dynamic Optimization"
.br
Adapting execution based on target resolution and performance needs

.SH
Resolution Independence: The Holy Grail
.PP
True resolution independence means graphics that look perfect at any scale:

.DS
/* Plan 9's approach to resolution independence */

// Define graphics in abstract coordinate space
Rectangle logical_rect = Rect(0, 0, 100, 100);

// Map to any physical resolution  
Rectangle physical_rect = scale_rect(logical_rect, target_dpi);

// Execute drawing routines at target resolution
draw_complex_graphic(display, physical_rect, target_dpi);
.DE

.PP
The same logical description produces:
.IP \(bu 3
Crisp 12px mobile icons
.IP \(bu
Sharp 24px desktop icons  
.IP \(bu
Perfect 64px toolbar graphics
.IP \(bu
Beautiful 300dpi print graphics

.SH
Practical Vector Graphics in Plan 9
.PP
To explore quantized routines and build sequences:

.DS
# Examine Plan 9's vector graphics tools
page /sys/src/libdraw/*.c    # Study the technique library
page /sys/src/cmd/plot/*     # Vector graphics applications

# Create your own build sequences  
cat > house.c << 'EOF'
#include <u.h>
#include <libc.h>  
#include <draw.h>

// Your quantized house-drawing routine here
EOF

# Compile and test at different scales
8c house.c && 8l -o house house.8
./house 32    # Small icon
./house 128   # Medium graphic  
./house 512   # Large illustration
.DE

.SH
Advanced Techniques: Adaptive Routines
.PP
Sophisticated vector graphics adapt their execution based on context:

.DS
/* Adaptive routine - changes behavior based on scale */
void draw_adaptive_icon(Image *dst, Rectangle r, char *icon_type) {
    int size = Dx(r);
    
    if (size < 16) {
        // Simplified routine for tiny sizes
        draw_icon_minimal(dst, r, icon_type);
    } else if (size < 64) {
        // Standard routine for normal sizes
        draw_icon_standard(dst, r, icon_type);  
    } else {
        // Enhanced routine for large sizes
        draw_icon_detailed(dst, r, icon_type);
    }
}
.DE

.SH
From Graphics to Services: The Bridge to Computing
.PP
Understanding vector graphics as quantized routines of applied technique 
naturally leads us to the next concept: service workers. Just as vector 
graphics encode artistic techniques as reproducible procedures, service 
workers encode computational techniques as reproducible services.

.PP
The same principles that make graphics scalable and resolution-independent 
make services scalable and platform-independent.

.SH
Key Concepts to Remember
.DS
Vector Graphics = Encoded artistic techniques, not fixed pixels
Quantization = Breaking techniques into reproducible steps  
Build Sequence = Step-by-step procedure for creating graphics
Dynamic Resolution = Automatic adaptation to any scale
Generative = Graphics that create themselves algorithmically
Resolution Independence = Perfect appearance at any size
Applied Technique = Specific method for achieving visual effect
.DE