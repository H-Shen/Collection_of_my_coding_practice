import numpy as np
from functools import reduce

N, M = list(map(int,input().split()))
result = list()
for _ in range(N):
    result.append(list(map(int,input().split())))
print(reduce(lambda x,y:x*y,list(np.sum(result, axis = 0))))
