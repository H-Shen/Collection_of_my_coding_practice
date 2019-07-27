#!/bin/python3

import math
import os
import random
import re
import sys
import string

def solve(a):
    a = a.split(' ')
    for i in range(len(a)):
        a[i] = string.capwords(a[i])
    a = ' '.join(a)
    return a

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = solve(s)

    fptr.write(result + '\n')

    fptr.close()
