# https://www.nowcoder.com/practice/5632c23d0d654aecbc9315d1720421c1

from itertools import permutations

try:
    while 1:
        a = list(permutations(sorted(raw_input())))
        b = len(a)
        for i in xrange(b - 1):
            print ''.join(a[i])
        print ''.join(a[- 1]) + '\n'
except:
    pass