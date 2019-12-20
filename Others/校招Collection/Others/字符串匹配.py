# https://www.nowcoder.com/practice/fbdc522ef958455687654b38a4ca01e0

import re

try:
    while 1:
        L, n = [], input()
        for i in xrange(n):
            L.append(raw_input())
        Pattern = raw_input()
        for j in xrange(n):
            a = re.findall(Pattern, L[j], flags=re.I)
            if len(a) == 1 and a[0] == L[j]:
                print j + 1, L[j]
except:
    pass