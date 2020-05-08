import numpy as np
n,l = list(map(int,input().split()))
result = list()
for i in range(n):
    s = input().split()
    result.append(list(map(int,s)))
k = np.min(result, axis = 1)
print(max(list(k)))
