# -*- coding: utf-8 -*-
# https://open.kattis.com/problems/smallestmultiple
#
from math import gcd
from functools import reduce

def lcm(a, b):
    return a * b // gcd(a, b)

try:
    while True:
        s = list(map(int, input().split()))
        print(reduce(lambda x, y : lcm(x, y), s))
except:
    pass

