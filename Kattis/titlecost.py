# https://open.kattis.com/problems/titlecost

from decimal import *

a, b = input().split()
a_val = Decimal(len(a))
b_val = Decimal(b)

if a_val < b_val:
    print(len(a))
else:
    print(b)
