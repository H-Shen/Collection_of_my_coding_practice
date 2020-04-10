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
echo "Output"
./FastIO out 1 10000000
./FastIO out 2 10000000
./FastIO out 3 10000000
./FastIO out 4 10000000
./FastIO out 5 10000000

# clean
rm -rf FastIO

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
echo "Output"
./FastIO out 1 10000000
./FastIO out 2 10000000
./FastIO out 3 10000000
./FastIO out 4 10000000
./FastIO out 5 10000000

# clean
rm -rf FastIO

#   2019-12-24
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

#    2020-04-10
#    Compiling ... OK
#    Test 10000000 integers:
#    Input
#    fread: 0.298954 seconds
#    getchar_unlocked: 0.419599 seconds
#    scanf: 1.64546 seconds
#    cin without sync: 1.49664 seconds
#    cin: 4.77755 seconds
#    Output
#    fwrite: 0.542893 seconds
#    putchar_unlocked: 0.632219 seconds
#    printf: 1.40839 seconds
#    cout without sync: 1.36093 seconds
#    cout: 32.9351 seconds