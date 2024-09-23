# https://www.nowcoder.com/practice/e3b2cc44aa9b4851bdca89dd79c53150

from collections import OrderedDict
try:
    while True:
        s = raw_input()
        result = OrderedDict()
        L = len(s)
        for i in xrange(L):
            if s[i] not in result:
                result[s[i]] = [i]
            else:
                result[s[i]].append(i)
        for j in result.items():
            if len(j[1]) > 1:
                a = str(j[0]) + ':'
                b = ',' + a
                print a + b.join(map(str, j[1]))
except:
    pass