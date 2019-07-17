#!/bin/python3

import sys

n = int(input().strip())
string = '#'
for i in range(n):
    print(string.rjust(n,' '))
    string += '#'