# https://open.kattis.com/problems/rationalsequence2
# -*- coding: utf-8 -*-

from fractions import Fraction as f

A = list()

def getParent(x):
    if (x < 1):
        A.append('L')
        return f(1, f(1, x) - 1)
    A.append('R')
    return x - 1

T = int(input())
for i in range(T):

    A.clear()
    case, s = input().split()
    s = f(s)

    while (s != 1):
        s = getParent(s)

    A.reverse()
    level = 1
    for i in A:
        if (i == 'L'):
            level = level * 2
        else:
            level = level * 2 + 1
    print(case + ' ' + str(level))
