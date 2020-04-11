#!/bin/bash

printf "Compiling ..."
g++ -std=c++17 -Wall -O2 FastIO.cpp -o FastIO
printf " OK\n"

echo "Test 10000000 integers:"
echo "Input"
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