# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6

class Solution:

    def fib(self):
        yield 1
        yield 2
        a, b = 1, 2
        while 1:
            a, b = b, a + b
            yield b

    def rectCover(self, number):
        if number == 0:
            return 0
        gen = self.fib()
        for i in range(number):
            current = next(gen)
        return current