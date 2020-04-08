# https://open.kattis.com/problems/rationalratio

from collections import deque
from fractions import Fraction as f

A = input().split()
p = deque(A[0])
if (p[0] == '.'):
    p.appendleft('0')
while (p[0] == '0' and p[1] == '0'):
    p.popleft()
left = ""
while (p[0] != '.'):
    left += p[0]
    p.popleft()
p.popleft()
k = int(A[1])
m = len(p) - k
b = ""
for i in range(0, m):
    b += p[i]
c = ""
for i in range(m, len(p)):
    c += p[i]
if b == "":
    b = "0"
if c == "":
    c = "0"
result = f(left) + f(int(b), pow(10, m)) + f(int(c), int('9' * len(c))) * f(1, pow(10, m))
print(str(result.numerator) + '/' + str(result.denominator))
