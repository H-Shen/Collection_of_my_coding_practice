# -*- coding: utf-8 -*-

import numpy as np
from numpy import linalg as la

# input
A = np.mat([[3, 0, 0, -2, 4],
            [0, 2, 0, 0, 0],
            [0, -1, 0, 5, -3],
            [-4, 0, 1, 0, 6],
            [0, -1, 0, 3, 2]])

# output
output = la.det(A)
print(int(round(output)))