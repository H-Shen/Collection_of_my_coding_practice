# -*- coding:utf-8 -*-

# https://www.nowcoder.com/practice/7f0661ace6df48d0af3f924950d57126

class GoUpstairs:
    def countWays(self, n):
        if n == 1:
            return 1
        if n == 2:
            return 2
        if n == 3:
            return 4
        a, b, c = 1, 2, 4
        for i in xrange(n - 3):
            a, b, c = b, c, (a + b + c) % 1000000007
        return c