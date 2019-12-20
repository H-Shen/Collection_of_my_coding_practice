# https://www.nowcoder.com/practice/02cb8d3597cf416d9f6ae1b9ddc4fde3

from collections import Counter

try:
    while 1:
        for i in xrange(input()):
            s = raw_input().lower()
            s = sorted(Counter(s).items(), key=lambda x:x[1], reverse=True)
            L = len(s)
            print sum([(26 - j) * s[j][1] for j in xrange(L)])
except:
    pass