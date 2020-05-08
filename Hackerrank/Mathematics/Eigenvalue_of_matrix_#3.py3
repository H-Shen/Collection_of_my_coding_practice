# -*- coding: utf-8 -*-

import numpy as np
from numpy import linalg as la

# input
A = np.mat([[2, -1], [-1, 2]])
B = A ** 2

# output
output0 = la.eigvals(A).tolist()
output1 = la.eigvals(B).tolist()

# the smaller value should be output firstly
print(int(round(min(output0))))
print(int(round(max(output0))))

print(int(round(min(output1))))
print(int(round(max(output1))))