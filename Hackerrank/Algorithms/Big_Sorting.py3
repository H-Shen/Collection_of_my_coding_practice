#!/bin/python3

import sys

n = int(input().strip())
unsorted = []
unsorted_i = 0
for unsorted_i in range(n):
    unsorted_t = str(input().strip())
    unsorted.append(unsorted_t)
# your code goes here
unsorted.sort(key = lambda x : (len(x), int(x)))
for i in range(n):
    print(unsorted[i])