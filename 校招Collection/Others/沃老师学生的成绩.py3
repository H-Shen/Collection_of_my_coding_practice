#!/usr/bin/env python
# https://ac.nowcoder.com/acm/problem/15610

from decimal import *
getcontext().prec = 2000

A = list()
n = int(input())
for i in range(n):
    name, score = input().split()
    tmp = (name, score, Decimal("-" + score))
    A.append(tmp)

A.sort(key = lambda x : (x[2], x[0]))

for i, j, k in A:
    print(i, j)