#!/bin/python3

import sys

n = int(input().strip())
calories = list(map(int, input().strip().split(' ')))
# your code goes here

calories.sort(reverse=True)
s = 0
for i in range(n):
    s = s + calories[i] * pow(2, i)
print(s)
