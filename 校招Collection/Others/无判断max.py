# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/b0a82250677a4fabb0bc41053fa05013

class Max:
    def getMax(self, a, b):
        # write code here
        # 在int范围内
        # (a - b) >> 31 为 0， 说明 a - b 最高位为0，即a >=b
        # (a - b) >> 31 为 -1, 说明 a - b 最高位为1， 即 a < b
        return {0: a, -1: b}[(a - b) >> 31]