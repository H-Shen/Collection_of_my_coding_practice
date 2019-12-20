# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/a386fd3a5080435dad3252bac76950a7
import re
pat = re.compile('coder', flags=re.I)

class Coder:
    def findCoder(self, A, n):

        result = []
        res = []
        length = len(A)

        for i in xrange(length):
            k = pat.findall(A[i])
            if k:
                result.append([A[i], len(k), i])

        result.sort(key=lambda x: (-x[1], x[2]))
        for u, v, w in result:
            res.append(u)

        return res