# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/33ad4d168a3247b9b63f41e4eaded652

class CloseNumber:
    def getCloseNumber(self, x):
        # write code here
        a = bin(x)
        num = a.count('1')
        Min, Max = x - 1, x + 1

        while (bin(Min).count('1') != num):
            Min -= 1
        while (bin(Max).count('1') != num):
            Max += 1
        return [Min, Max]