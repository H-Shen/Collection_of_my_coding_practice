# -*- coding: utf-8 -*-

import numpy as np

# input
A = np.mat([[1, 2], [2, 3]])
B = np.mat([[4, 5], [7, 8]])
C = A * B

# output
output = C.tolist()
for i in output:
    for j in i:
        print(j)