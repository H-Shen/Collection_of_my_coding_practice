EPS = 1e-8

def sgn(a):
    if (a < -EPS):
        return -1
    if (a < EPS):
        return 0
    return 1

a = float(input())
s = 0.0
m = 1
n = 1
i = 1
while True:
    if (i == 1 or i == 2):
        m = 1
    else:
        m = m * (i - 1)
    n = n * (2 * i - 1)
    lastTerm = m / n
    s += lastTerm * 2.0
    if sgn(lastTerm - a) <= 0:
        break
    i += 1
print('%.6f' % s)