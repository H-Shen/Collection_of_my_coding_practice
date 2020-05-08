from math import log

import heapq

A = []
n = int(input())
for i in range(n):
    a, b = list(map(int, input().split()))
    A.append([b * log(a), a, b])
k = int(input())
result = heapq.nsmallest(k, A, key = lambda x : x[0])[-1]
print(result[1], result[2])
