#!/bin/bash

# This script compiles the C source files, links them, and runs the resulting executable.

# Exit immediately if a command exits with a non-zero status.
set -e

echo "--- Compiling animal.c ---"
gcc -c animal.c -o animal.o

echo "--- Compiling tiger.c ---"
gcc -c tiger.c -o tiger.o

echo "--- Compiling main.c ---"
gcc -c main.c -o main.o

echo "--- Linking object files ---"
gcc animal.o tiger.o main.o -o prog.out

echo "--- Running program ---"
./prog.out

echo "--- Cleaning up object files ---"
rm animal.o tiger.o main.o

echo "--- Done ---"