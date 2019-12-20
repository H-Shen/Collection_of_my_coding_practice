# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993

from itertools import permutations
class Solution:
    def PrintMinNumber(self, numbers):
        # write code here
        if numbers == []:
            return ''
        a = list(set(numbers))
        gen = permutations(a)
        result = int(''.join(map(str, next(gen))))
        try:
            while 1:
                current = int(''.join(map(str, next(gen))))
                if current < result:
                    result = current
        except:
            pass
        return result