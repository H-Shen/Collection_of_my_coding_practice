# https://open.kattis.com/problems/sok

from fractions import Fraction as f

a, b, c = list(map(int, input().split()))
i, j, k = list(map(int, input().split()))
s = i + j + k

L = min(f(s * a, i), f(s * b, j), f(s * c, k))

x1 = L * f(i, s)
x2 = L * f(j, s)
x3 = L * f(k, s)

print("%.6f" % (a - x1) + " " + "%.6f" % (b - x2) + " " + "%.6f" % (c - x3))
