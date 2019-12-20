# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163

class Solution:
    def MoreThanHalfNum_Solution(self, numbers):
        # write code here
        a = list(set(numbers))
        l = len(numbers)
        result = filter(lambda x:numbers.count(x) > l / 2, a)
        return 0 if len(result) == 0 else result[0]
