# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/a0c19f3489774fe693d71490ce83b648

class NextElement:
    def findNext(self, A, n):
        # write code here
        result = list()
        for i in xrange(n):
            try:
                result.append(min(filter(lambda x: x > A[i], A[i + 1:])))
            except:
                result.append(-1)
        return result