# https://www.nowcoder.com/practice/e58c8a55162d49c48115bdfa5da7da56

from math import factorial as f

def a(n):
    if n == 2:
        return '1 2'
    if n == 1:
        return '1'
    if n % 2 == 0:
        return ' '.join(map(str,(sum(map(f, xrange(1, n + 1, 2))),sum(map(f, xrange(2, n + 2, 2))))))
    else:
        return ' '.join(map(str,(sum(map(f, xrange(1, n + 2, 2))),sum(map(f, xrange(2, n + 1, 2))))))
try:
    while 1:
        print a(input())
except:
    pass