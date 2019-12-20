# https://www.nowcoder.com/practice/33b1a1a460914456ae2b3afb16f095af

from collections import Counter

try:
    while 1:
        M, N = map(int, raw_input().split())
        m, n = map(int, raw_input().split()), map(int, raw_input().split())
        L = list(set(m) & set(n))
        a, b, count = Counter(m), Counter(n), 0
        for i in L:
            count += min([a, b], key=lambda x: x[i])[i]
        print count
except:
    pass