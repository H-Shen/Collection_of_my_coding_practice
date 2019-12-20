# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/6f8c901d091949a5837e24bb82a731f2

class Solution:
    # s字符串
    def isNumeric(self, s):
        # write code here
        try:
            a = float(s)
            return True
        except:
            return False