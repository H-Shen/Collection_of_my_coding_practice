# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/1f7675ae7a9e40e4bd04eb754b62fd00
class LongestDistance:
    def getDis(self, A, n):
        # write code here
        MAX = 0
        for a in xrange(n):
            for b in xrange(a, n):
                current = A[b] - A[a]
                if current > MAX:
                    MAX = current
        return MAX