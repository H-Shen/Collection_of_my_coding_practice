# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e

class Solution:
    def StrToInt(self, s):
        L = len(s)
        result = 0
        Flag = 1
        if L == 0:
            return result
        if s[0] == '+':
            if L == 1:
                return 0
            s = s[1:]
            L -= 1
        if s[0] == '-':
            if L == 1:
                return 0
            L -= 1
            s = s[1:]
            Flag = 0
        for i in xrange(L):
            current = ord(s[i])
            if current > 57 or current < 48:
                return 0
            result += (current - 48) * 10 ** (L - i - 1)
        if Flag == 0:
            return result * (-1)
        return result


