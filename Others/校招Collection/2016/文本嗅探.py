# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/6b372fae97c84c3681d2be03923e7eaa
class KeywordDetect:
    def containKeyword(self, A, n, keys, m):
        # write code here
        a = []
        for i in keys:
            for j in xrange(n):
                if i in A[j]:
                    a.append(j)
        if a == []:
            return [-1]
        return sorted(set(a))