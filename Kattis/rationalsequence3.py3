# -*- coding: utf-8 -*-
# https://open.kattis.com/problems/rationalsequence3

from fractions import Fraction as f

def getLeftChild(x):
    return f(1, 1 + f(1, x))
def getRightChild(x):
    return x + 1

Level = list()

T = int(input())
for i in range(T):

    Level.clear()
    case, level = input().split()
    
    level = int(level)
    while (level != 1):
        if (level % 2 == 0):
            Level.append('L')
            level //= 2
        else:
            Level.append('R')
            level -= 1
            level //= 2
    Level.reverse()

    root = f(1)
    for i in Level:
        if (i == 'L'):
            root = getLeftChild(root)
        else:
            root = getRightChild(root)
    print(case + ' ' + str(root.numerator) + '/' + str(root.denominator))
