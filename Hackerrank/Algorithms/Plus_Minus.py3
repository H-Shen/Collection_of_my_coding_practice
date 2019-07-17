#!/bin/python3

import sys

n = int(input().strip())
arr = [int(arr_temp) for arr_temp in input().strip().split(' ')]

a, b, c = 0, 0, 0

for i in range(len(arr)):
    if arr[i] == 0:
        c += 1
    elif arr[i] > 0:
        a += 1
    else:
        b += 1

a = str(round(a/n,6)).ljust(8,'0')
b = str(round(b/n,6)).ljust(8,'0')
c = str(round(c/n,6)).ljust(8,'0')

print(a)
print(b)
print(c)
