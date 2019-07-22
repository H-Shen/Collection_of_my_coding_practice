# https://www.nowcoder.com/practice/fbc417f314f745b1978fc751a54ac8cb

from __future__ import division
from itertools import product, permutations


formula = ["(%d %s %d) %s (%d %s %d)",
           "((%d %s %d) %s %d) %s %d",
           "(%d %s (%d %s %d)) %s %d",
           "%d %s ((%d %s %d) %s %d)",
           "%d %s (%d %s (%d %s %d))"]

operations = list(product(['+', '-', '*', '/'], repeat=3))

def validation(formula, numList, operations):
    a, b, c, d = numList
    op1, op2, op3 = operations
    e = formula % (a, op1, b, op2, c, op3, d)
    try:
        result = eval(e)
    except:
        return False
    if 23.999 <= result <= 24.001:
        return True
    return False

def calc24():
    global formula, operations, numTable
    for numList in numTable:
        for i in operations:
            for j in formula:
                if validation(j, numList, i):
                    return 'true'
                    break
    return 'false'

try:
    while 1:
        a = map(int, raw_input().split())
        numTable = list(permutations(a))
        print calc24()
except:
    pass