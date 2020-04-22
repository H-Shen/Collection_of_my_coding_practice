#!/bin/bash

printf "Compiling ..."
g++ -std=c++17 -Wall -O2 FastIO.cpp -o FastIO
printf " OK\n"

echo "Test 10000000 integers:"
echo "Input"
./FastIO in 0 10000000
./FastIO in 1 10000000
./FastIO in 2 10000000
./FastIO in 3 10000000
./FastIO in 4 10000000
./FastIO in 5 10000000
./FastIO in 6 10000000
echo "Output"
./FastIO out 1 10000000
./FastIO out 2 10000000
./FastIO out 3 10000000
./FastIO out 4 10000000
./FastIO out 5 10000000
./FastIO out 6 10000000
# clean
rm -rf FastIO

#    Compiling ... OK
#    Test 10000000 integers:
#    Input
#    mmap: 0.333833 seconds
#    fread: 0.493002 seconds
#    getchar unlocked: 0.433707 seconds
#    scanf: 1.62939 seconds
#    cin without sync: 1.7917 seconds
#    cin: 5.04564 seconds
#    getchar: 0.619069 seconds
#    Output
#    fwrite: 0.735085 seconds
#    fwrite: 0.749883 seconds
#    putchar unlocked: 0.826488 seconds
#    printf: 1.41162 seconds
#    cout without sync: 1.36623 seconds
#    cout: 30.6118 seconds
#    putchar: 0.815868 seconds