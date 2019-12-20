# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593

class Solution:
    def reOrderArray(self, array):
        # write code here
        odd, even = list(), list()
        for i in array:
            if (i & 1) == 0:
                even.append(i)
            else:
                odd.append(i)
        return odd + even