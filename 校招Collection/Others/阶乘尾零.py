# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/434922f9f4724b97b83c417e884008f1

class Factor:
    def getFactorSuffixZero(self, n):
        # write code here
        result = 0
        while n > 0:
            result += n / 5
            n /= 5
        return result