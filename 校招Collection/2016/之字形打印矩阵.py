# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/7df39c7556424eada267d8f793961a1e

class Printer:
    def printMatrix(self, mat, n, m):
        # write code here
        result = list()
        for i in xrange(n):
            if i % 2 == 0:
                result.extend(mat[i])
            else:
                result.extend(mat[i][::-1])
        return result