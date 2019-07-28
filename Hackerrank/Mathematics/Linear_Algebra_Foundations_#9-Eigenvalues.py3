# -*- coding: utf-8 -*-

import numpy as np
from numpy import linalg as la

# input
A = np.mat([[0, 1], [-2, -3]])

# output
output = la.eigvals(A).astype(int).tolist()

# the smaller value should be output firstly
output.sort()
for i in output:
    print(i)