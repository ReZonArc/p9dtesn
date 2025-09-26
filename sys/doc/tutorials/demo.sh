#!/bin/sh
# Demo script showing the progressive tutorial series
# Plan 9 Beginner Tutorials: From Drawing Terminals to Kawaii Cognition

echo "Plan 9 Beginner Tutorial Series Demo"
echo "====================================="
echo
echo "This tutorial series transforms complex Plan 9 concepts into"
echo "accessible, creative learning through progressive metaphors:"
echo

echo "1. Drawing a Terminal (drawterm-beginners/)"
echo "   → Learn to 'paint' windows into distant Plan 9 systems"
head -5 drawterm-beginners/01-drawing-a-terminal.ms | grep -v "^\." | head -3
echo

echo "2. Drawing a Kernel (drawkern/)"  
echo "   → Extend drawing concepts to system kernel creation"
head -15 drawkern/02-drawing-a-kernel.ms | grep -v "^\." | head -3
echo

echo "3. Kernels as Seeds (kernels-as-seeds/)"
echo "   → Understanding systems as growing digital ecosystems"
head -15 kernels-as-seeds/03-kernels-as-seeds.ms | grep -v "^\." | head -3
echo

echo "4. Fonts as Gestures (fonts-as-gestures/)"
echo "   → Typography as dynamic, expressive language"
head -15 fonts-as-gestures/04-fonts-as-gestures.ms | grep -v "^\." | head -3
echo

echo "5. Vector Graphics (vector-graphics/)"
echo "   → Quantized routines for resolution-independent art"
head -15 vector-graphics/05-vector-graphics-dynamic-resolution.ms | grep -v "^\." | head -3
echo

echo "6. Service Workers (service-workers/)"
echo "   → Hidden canvas where background services paint functionality"
head -15 service-workers/06-reveal-hidden-canvas-service-workers.ms | grep -v "^\." | head -3
echo

echo "7. Distributed Cognition (distributed-cognition/)"
echo "   → Kawaii worker teams with personalities and chatbot abilities"
head -15 distributed-cognition/07-distributed-cognition-kawaii-workers.ms | grep -v "^\." | head -3
echo

echo "Tutorial Structure:"
find . -name "*.ms" | sort
echo

echo "Example Code:"
find . -name "*.c" -o -name "Makefile" | sort
echo

echo "To start learning:"
echo "1. Read README.ms for the complete overview"
echo "2. Work through tutorials 01-07 in sequence"  
echo "3. Try the example code in distributed-cognition/examples/"
echo "4. Build your own kawaii workers!"
echo
echo "Happy learning! (◕‿◕)✨"