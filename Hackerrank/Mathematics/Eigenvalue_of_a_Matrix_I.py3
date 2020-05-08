# -*- coding: utf-8 -*-

import numpy as np
from numpy import linalg as la

# input
A = np.mat([[1, -3, 3], [3, -5, 3], [6, -6, 4]])

# output
output = la.eigvals(A).tolist()

# the smaller value should be output firstly
print(int(round(min(output))))
print(int(round(max(output))))