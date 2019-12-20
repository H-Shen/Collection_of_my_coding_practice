# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3

class Solution:
    def Fibonacci(self, n):
        # write code here
        L = [0, 1, 1]
        if n < 3:
            return L[n]
        while n > 2:
            L.append(L[-1] + L[-2])
            n -= 1
        return L[-1]