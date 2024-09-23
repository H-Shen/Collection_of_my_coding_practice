# https://www.nowcoder.com/practice/42cb1c7f7344466b8cb1710cb12d06b1

from math import factorial
from itertools import combinations

a = [factorial(i) for i in xrange(1, 10)] + [1]
table = set()

for i in xrange(1, 10):
    table |= set(map(sum, combinations(a, i)))

try:
    while 1:
        print 'YES' if input() in table else 'NO'
except:
    pass
