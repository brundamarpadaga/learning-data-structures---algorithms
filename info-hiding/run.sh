#!/bin/bash

# This script compiles the C source files, links them, and runs the resulting executable.

# Exit immediately if a command exits with a non-zero status.
set -e

echo "--- Compiling list.c ---"
gcc -c list.c -o list.o

echo "--- Compiling main.c ---"
gcc -c main.c -o main.o

echo "--- Linking object files ---"
gcc main.o list.o -o prog.out

echo "--- Running program ---"
./prog.out

echo "--- Cleaning up object files ---"
rm main.o list.o

echo "--- Done ---"
