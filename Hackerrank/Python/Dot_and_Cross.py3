import numpy as np

A, B = list(), list()
n = int(input())

for _ in range(n):
    A.append(list(map(int,input().split())))
for _ in range(n):
    B.append(list(map(int,input().split())))

A = np.array(A)
B = np.array(B)
print(np.dot(A, B))
