# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/30c1674ad5694b3f8f0bc2de6f005490

class BinInsert:
    def binInsert(self, n, m, j, i):
        # write code here
        K, J = list(bin(n)[2:]), list(bin(m)[2:])
        return int(''.join(K[:-j-len(J)] + J + K[-j:]), 2)