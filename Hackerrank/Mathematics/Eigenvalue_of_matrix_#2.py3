# -*- coding: utf-8 -*-

import numpy as np
from numpy import linalg as la

# input
A = np.mat([[1, 2], [2, 4]])

# output
output = la.eigvals(A).tolist()

# the smaller value should be output firstly
print(int(round(min(output))))
print(int(round(max(output))))