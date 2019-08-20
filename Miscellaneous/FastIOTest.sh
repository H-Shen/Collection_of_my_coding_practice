#!/bin/bash

g++ -std=c++14 -Wall -O2 FastIO.cpp -o FastIO
echo "Test 10000000 integers:"
echo "Input"
./fastIO in 1 10000000
./fastIO in 2 10000000
./fastIO in 3 10000000
./fastIO in 4 10000000
./fastIO in 5 10000000
echo "Output"
./fastIO out 2 10000000
./fastIO out 3 10000000
./fastIO out 4 10000000
./fastIO out 5 10000000

# clean
rm -rf FastIO

#Test 10000000 integers:
#Input
#fread: 0.503773 seconds
#readInt: 0.602472 seconds
#scanf: 1.70843 seconds
#cin: 5.11469 seconds
#cin without sync: 1.75088 seconds
#Output
#putchar: 0.87661 seconds
#printf: 1.42188 seconds
#cout: 27.4936 seconds
#cout without sync: 1.66747 seconds
