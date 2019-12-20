# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4

class Solution:
    def jumpFloor(self, n):
        # write code here
        L = [0, 1, 2]
        if n < 3:
            return L[n]
        while n > 2:
            L.append(L[-1] + L[-2])
            n -= 1
        return L[-1]