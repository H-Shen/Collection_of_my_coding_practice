# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/c7df20a5a39e4357aecc1071e7fd523c

class Transform:
    def calcCost(self, A, B):
        # write code here
        a, b = bin(A)[2:], bin(B)[2:]
        c = len(max([a, b], key=len))
        a, b = a.zfill(c), b.zfill(c)
        count = 0
        for i in xrange(c):
            if a[i] != b[i]:
                count += 1
        return count