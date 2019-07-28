# -*- coding: utf-8 -*-

import numpy as np

# input
A = np.mat([[1, 1, 0], [0, 1, 0], [0, 0, 1]])
C = A ** 100

# output
output = C.tolist()
print(output[0][0])
print(output[0][1])
print(output[1][1])
print(output[2][1])
print(output[2][2])