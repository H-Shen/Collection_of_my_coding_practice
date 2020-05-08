# -*- coding: utf-8 -*-

import numpy as np

# input
A = np.mat([[-2, -9], [1, 4]])
C = A ** 1000

# output
output = C.tolist()
for i in output:
    for j in i:
        print(j)