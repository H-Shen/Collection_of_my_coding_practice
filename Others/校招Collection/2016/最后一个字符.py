# https://www.nowcoder.com/practice/87608e500bb24e1782278154a1e43983

try:
    while 1:
        T = input()
        for i in xrange(T):
            RepeatedString, L = set(), []
            s = raw_input()
            for j in s:
                if j in L:
                    del L[L.index(j)]
                    RepeatedString.add(j)
                elif j in RepeatedString:
                    continue
                else:
                    L.append(j)
            print L[0]
except:
    pass