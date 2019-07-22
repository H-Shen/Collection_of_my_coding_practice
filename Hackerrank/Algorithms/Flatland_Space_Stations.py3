#!/bin/python3

import sys

a = list(map(int,input().split()))
n,m = a
listm = list(map(int,input().split()))
L = sorted(listm)

result = []

if n == m:
    print(0)
elif m == 1:
    print(n - 1)
else:
    for i in range(1,len(L)):
        result.append(L[i] - L[i - 1])

    start = L[0]
    end = n - 1 - L[-1]
    c = max(result)

    if c % 2 == 0:
        final = max([c // 2,start,end])
        print(final)
    else:
        final = max([(c - 1) // 2,start,end])
        print(final)
