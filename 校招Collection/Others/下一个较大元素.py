# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/11ae41035eef4ed9b354d0752f5abc6f

class NextElement:
    def findNext(self, A, n):
        # write code here
        result = []
        for i in xrange(n):
            flag = False
            for j in A[i + 1:]:
                if j > A[i]:
                    result.append(j)
                    flag = True
                    break
            if flag == False:
                result.append(-1)
        return result