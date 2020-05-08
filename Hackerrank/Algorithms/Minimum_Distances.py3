#!/bin/python3

import sys

n = int(input().strip())
A = [int(A_temp) for A_temp in input().strip().split(' ')]

reverseA = A[:]
reverseA = reverseA[::-1]
setA = list(set(A))
countsetA = []

for i in range(len(setA)):
    countsetA.append(A.count(setA[i]))

result = []
for j in range(len(countsetA)):
    if countsetA[j] != 1:
        pos_i = A.index(setA[j])
        pos_j = reverseA.index(setA[j])
        pos_j = len(A) - 1 - pos_j
        D = abs(pos_i - pos_j)
        result.append(D)

if result == []:
    print(-1)
else:
    print(min(result))
