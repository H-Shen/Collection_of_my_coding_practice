# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/2e95333fbdd4451395066957e24909cc

class Rotate:
    def rotateMatrix(self, mat, n):
        # write code here
        return map(lambda x:list(x)[::-1], zip(*mat))