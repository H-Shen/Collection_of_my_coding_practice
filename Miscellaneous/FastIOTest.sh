#!/bin/bash

printf "Compiling ..."
g++ -std=c++14 -Wall -O2 FastIO.cpp -o FastIO
printf " OK\n"

echo "Test 10000000 integers:"
echo "Input"
./FastIO in 1 10000000
./FastIO in 2 10000000
./FastIO in 3 10000000
./FastIO in 4 10000000
./FastIO in 5 10000000
echo "Output"
./FastIO out 1 10000000
./FastIO out 2 10000000
./FastIO out 3 10000000
./FastIO out 4 10000000
./FastIO out 5 10000000

# clean
rm -rf FastIO

#	Compiling ... OK
#	Test 10000000 integers:
#	Input
#	fread: 0.383157 seconds
#	readInt: 0.591193 seconds
#	scanf: 1.63778 seconds
#	cin without sync: 1.75131 seconds
#	cin: 5.07233 seconds
#	Output
#	fwrite: 0.585462 seconds
#	putchar: 0.90512 seconds
#	printf: 1.419 seconds
#	cout without sync: 1.38518 seconds
#	cout: 27.208 seconds
