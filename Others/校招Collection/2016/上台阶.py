# -*- coding:utf-8 -*-

# https://www.nowcoder.com/practice/4b24ebad2ffd4f679320fd464b2036a6

def MatrixMul(a, b):
    r = [[0, 0], [0, 0]]
    r[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) % 1000000007
    r[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % 1000000007
    r[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % 1000000007
    r[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % 1000000007
    return r

def QuickMatrixPower(A, n):
    if n == 1:
        return A
    Temp = QuickMatrixPower(A, n / 2)
    if n % 2 == 1:
        return MatrixMul(MatrixMul(Temp, Temp), A)
    return MatrixMul(Temp, Temp)

class GoUpstairs:
    def countWays(self, n):
        # write code here
        if n <= 3:
            return [0, 1, 2][n - 1]
        else:
            return MatrixMul(QuickMatrixPower([[1, 1],[1, 0]], n - 2),[[1, 2],[1, 1]])[0][0] % 1000000007