# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/e8bb8e68434e42acbcdff0341f2a32c5

class Robot:
    def countWays(self, x, y):
        # write code here
        from math import factorial
        return factorial(x - 1 + y - 1) // (factorial(x - 1) * factorial(y - 1))