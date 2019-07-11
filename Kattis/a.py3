#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# https://open.kattis.com/problems/asciifigurerotation
firstCase = True

while 1:

    n = int(input())
    if n == 0:
        break

    if not firstCase:
        print()

    A = list()
    maxLen = -1
    for i in range(n):
        s = input().rstrip()
        maxLen = max(maxLen, len(s))
        A.append(s)

    for i in range(n):
        if len(A[i]) != maxLen:
            A[i] = A[i] + ' ' * (maxLen - len(A[i]))

    A = list(zip(*A))
    for i in range(len(A)):
        A[i] = list(reversed(list(A[i])))

    for i in range(len(A)):
        for j in range(len(A[i])):
            if A[i][j] == '|':
                A[i][j] = '-'
            elif A[i][j] == '-':
                A[i][j] = '|'

    for i in range(len(A)):
        tmp = ''.join(A[i])
        A[i] = tmp.rstrip()

    for i in A:
        print(i)

    if firstCase:
        firstCase = False
