# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/93579c39385447f3a0ea5759902e3e0c

class Middle:
    def getMiddle(self, A, n):
        # write code here
        from heapq import nsmallest
        result = []
        for i in xrange(n):
            if i % 2 == 0:
                result.append(nsmallest(i // 2 + 1, A[:i + 1])[-1])
            else:
                result.append(nsmallest((i + 1) // 2,  A[:i + 1])[-1])
        return result