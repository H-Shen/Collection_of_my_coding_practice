from fractions import gcd
from functools import reduce

def multiGcd(L):
    if len(L) == 1:
        return False
    if len(L) == 2:
        return gcd(L[0], L[1]) == 1
    return reduce(lambda x, y: gcd(x, y), L) == 1


n = int(input())
for i in range(n):
    m = int(input())
    arr = list(set(map(int, input().split())))
    if multiGcd(arr):
        print('YES')
    else:
        print('NO')
