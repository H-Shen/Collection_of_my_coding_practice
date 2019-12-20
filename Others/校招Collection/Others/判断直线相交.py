# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/1efe2386491f4235b78a34cd1b5fb3d0

class CrossLine:
    def checkCrossLine(self, s1, s2, y1, y2):
        # write code here
        return False if (s1 == s2 and y1 != y2) else True