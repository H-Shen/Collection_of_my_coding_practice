# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/376ede61d9654bc09dd7d9fa9a4b0bcd

class MaxDivision:
    def findMaxDivision(self, A, n):
        # write code here
        N = max(n, max(A))
        List = (N + 1) * [0]
        result = list()
        for i in xrange(n):
            List[A[i]] += 1
        for j in xrange(N + 1):
            if List[j] != 0:
                result += List[j] * [j]
        sub = 0
        for i in xrange(1, n):
            a = abs(result[i] - result[i - 1])
            if a > sub:
                sub = a
        return sub