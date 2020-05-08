from itertools import product

A = list(map(int,input().strip().split()))
B = list(map(int,input().strip().split()))
C = list(product(A, B))
C.sort()

for i in range(len(C)):
    print(C[i],end = ' ')
