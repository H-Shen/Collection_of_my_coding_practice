# -*- coding: utf-8 -*-

import numpy as np

# input
A = np.mat([[1, 2, 3], [2, 3, 4], [1, 1, 1]])
B = np.mat([[4, 5, 6], [7, 8, 9], [4, 5, 7]])
C = A * B

# output
output = C.tolist()
for i in output:
    for j in i:
        print(j)