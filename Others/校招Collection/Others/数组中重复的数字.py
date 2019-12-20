# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8

class Solution:
    # 这里要特别注意~找到任意重复的一个值并赋值到 duplication[0]
    # 函数返回 True/False
    def duplicate(self, numbers, duplication):
        # write code here
        a = {}
        for i in numbers:
            if i in a:
                duplication[0] = i
                return True
            else:
                a[i] = 0
        return False