# https://open.kattis.com/problems/temperatureconfusion

from fractions import Fraction as f

a, b = list(map(int, input().split('/')))

res = f(5 * a - 160 * b, 9 * b)
print(str(res.numerator) + '/' + str(res.denominator))
