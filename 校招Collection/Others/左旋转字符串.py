# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec

class Solution:
    def LeftRotateString(self, s, n):
        # write code here
        return s[n:] + s[:n]