# -*- coding: utf-8 -*-
# https://open.kattis.com/problems/jointattack
#
from fractions import Fraction as f

n = int(input())
A = list(map(int, input().split()))
A.reverse()


x = 0
for i in range(len(A)):
    if i == len(A) - 1:
        x = A[i] + x
    elif i == 0:
        x = f(1, A[i])
    else:
        x = f(1, A[i] + x)
print(x)
