# https://ac.nowcoder.com/acm/problem/16780

from math import factorial

A = [factorial(i) for i in range(1, 50 + 1)]
N = int(input())

S = 0
for i in range(N):
    S += A[i]
print(S)