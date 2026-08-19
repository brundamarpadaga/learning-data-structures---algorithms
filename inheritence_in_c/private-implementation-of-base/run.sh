#!/bin/bash

# This script compiles the C source files, links them, and runs the resulting executable.

# Exit immediately if a command exits with a non-zero status.
set -e

echo "--- Compiling person.c ---"
gcc -c person.c -o person.o

echo "--- Compiling student.c ---"
gcc -c student.c -o student.o

echo "--- Compiling main.c ---"
gcc -c main.c -o main.o

echo "--- Linking object files ---"
gcc person.o student.o main.o -o prog.out

echo "--- Running program ---"
./prog.out

echo "--- Cleaning up object files ---"
rm person.o student.o main.o

echo "--- Done ---"