import numpy as np

result = list()
for _ in range(list(map(int,input().split()))[0]):
    result.append(list(map(int,input().split())))
print(np.transpose(np.array(result)))
print(np.array(result).flatten())
