# https://www.nowcoder.com/practice/ca319fdb02714994850cc631d76f5547

from __future__ import division

try:
    while 1:
        n, s = input(), 0
        for i in xrange(n):
            s += input()
        avg = s / n
        print "%.2f" %avg
except:
    pass