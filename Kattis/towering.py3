# https://open.kattis.com/problems/towering
from itertools import combinations

*a, b, c = list(map(int, input().split()))

s = combinations(a, 3)
A = list()
B = list()

try:
    while 1:
        A = list(next(s))
        if A[0] + A[1] + A[2] == b:
            break
except:
    pass

for i in a:
    if not i in A:
        B.append(i)

A.sort(reverse = True)
B.sort(reverse = True)

for i in range(len(A)):
    A[i] = str(A[i])
for i in range(len(B)):
    B[i] = str(B[i])
print(' '.join(A) + ' ' + ' '.join(B))
