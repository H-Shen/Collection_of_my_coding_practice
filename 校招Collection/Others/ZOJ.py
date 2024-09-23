# https://www.nowcoder.com/practice/7557d470617c464f9200d93acf721471

from collections import Counter
table = ['Z', 'O', 'J']

try:
    while 1:
        s = raw_input()
        if s == 'E':
            break
        a = [''] * len(s)
        b = sorted(Counter(s).items(), key=lambda x: table.index(x[0]))
        for i, j in b:
            for count in xrange(j):
                a[count] += i
        print ''.join(a)
except:
    pass