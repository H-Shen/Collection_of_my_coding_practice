# https://www.nowcoder.com/practice/4ec4325634634193a7cd6798037697a8

from collections import Counter

try:
    while 1:
        Query = raw_input()
        if Query == '#':
            break
        s = raw_input()
        Table = Counter(s)
        for i in Query:
            print i, Table[i]
except:
    pass
