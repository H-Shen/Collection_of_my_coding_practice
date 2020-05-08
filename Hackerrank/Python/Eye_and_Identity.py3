import numpy as np
np.set_printoptions(sign=' ')
a, b = list(map(int,input().split()))
A = np.eye(a, b, k = 0)
print(A)
