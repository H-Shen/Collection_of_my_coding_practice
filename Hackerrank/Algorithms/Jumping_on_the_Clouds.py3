#!/bin/python3

import sys

n = int(input().strip())
c = [int(c_temp) for c_temp in input().strip().split(' ')]

cCopy = c[:]
count = 0

while len(cCopy) != 1:
    try:
        cCopy[2] == 0
    except:
        count += 1
        break
    else:
        if cCopy[2] != 0:
            count += 1
            del cCopy[0]
        elif cCopy[2] == 0:
            count += 1
            del cCopy[0],cCopy[0]

print(count)
