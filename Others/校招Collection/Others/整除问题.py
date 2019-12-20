# https://www.nowcoder.com/practice/8e29045de1c84d349b43fdb123ab586a

from math import factorial as f

n, a = map(int, raw_input().split())
s = f(n)
k = 0
while s % a == 0:
    k += 1
    s //= a
print k