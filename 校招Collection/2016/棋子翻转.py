# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/0b5ab6cc51804dd59f9988ad70d8c4a0

class Flip:
    def swap(self, a):
        return 0 if a == 1 else 1
    def flipChess(self, A, f):
        for k in f:
            k[0] -= 1
            k[1] -= 1
            if k[1] - 1 >= 0:
                A[k[0]][k[1] - 1] = self.swap(A[k[0]][k[1] - 1])
            if k[0] - 1 >= 0:
                A[k[0] - 1][k[1]] = self.swap(A[k[0] - 1][k[1]])
            try:
                A[k[0]][k[1] + 1] = self.swap(A[k[0]][k[1] + 1])
            except:
                pass
            try:
                A[k[0] + 1][k[1]] = self.swap(A[k[0] + 1][k[1]])
            except:
                pass
        return A