# https://open.kattis.com/problems/rationalarithmetic

from fractions import Fraction as f

q = int(input())
for i in range(q):
    x1, y1, op, x2, y2 = input().split()
    x1 = int(x1)
    y1 = int(y1)
    x2 = int(x2)
    y2 = int(y2)
    res = 0
    if op == "+":
        res = f(x1, y1) + f(x2, y2)
    elif op == "-":
        res = f(x1, y1) - f(x2, y2)
    elif op == "*":
        res = f(x1, y1) * f(x2, y2)
    else:
        res = f(x1, y1) / f(x2, y2)
    print(str(res.numerator) + " / " + str(res.denominator))

