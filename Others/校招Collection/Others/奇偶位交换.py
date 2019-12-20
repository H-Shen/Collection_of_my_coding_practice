# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/ed7d014b42e740679c4bd69b9d9c49b9

class Exchange:
    def exchangeOddEven(self, x):
        # write code here
        a = bin(x)[2:]
        if len(a) % 2 != 0:
            a = '0' + a
        L = len(a)
        return int(''.join([a[i + 1] + a[i] for i in range(0, L, 2)]), 2)