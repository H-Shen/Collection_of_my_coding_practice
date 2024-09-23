# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/85062aa6016640d188a6a0daf9f5da0e

class StringRotation:
    def rotateString(self, A, n, p):
        return A[p + 1:] + A[:p + 1]