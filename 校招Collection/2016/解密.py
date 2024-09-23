# https://www.nowcoder.com/practice/1f16639196e7463189dc6a0e3b968185

from itertools import permutations
try:
    while 1:
        s = sorted(raw_input())
        gen = permutations(s)
        try:
            while 1:
                print ''.join(next(gen))
        except:
            pass
except:
    pass