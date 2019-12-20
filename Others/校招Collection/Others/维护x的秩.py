# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/0ade0d95c85349beb934a90b1d9b02be

class Rank:
    def getRankOfNumber(self, A, n):
        # write code here
        result = list()
        for i in xrange(n):
            result.append(len(list(filter(lambda x: x <= A[i], A[:i + 1]))) - 1)
    	return result
