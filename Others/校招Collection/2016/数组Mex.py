# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/9e7a6bcdbce74feb8013d252d76855da

class ArrayMex:
    def findArrayMex(self, A, n):
        i = 0
        items = A
        for j in xrange(n):
            if n >= items[j] > 0:
                items[i] = items[j]
                i += 1

        for k in xrange(i):
            v = abs(items[k])
            items[v - 1] = - abs(items[v - 1])

        for w in xrange(i):
            if items[w] > 0:
                return w + 1

        return i + 1