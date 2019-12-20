# -*- coding:utf-8 -*-

# https://www.nowcoder.com/practice/f094aed769d84cf3b799033c82fc1bf6
class StringFormat:
    def formatString(self, A, n, arg, m):
        # write code here
        a = A.count('%s')
        if a < m:
            arg_head = tuple(arg[:-(m - a)])
            arg_tail = arg[-(m - a):]
            current = A % arg_head + ''.join(arg_tail)
            return current
       	else:
            return A % tuple(arg)
