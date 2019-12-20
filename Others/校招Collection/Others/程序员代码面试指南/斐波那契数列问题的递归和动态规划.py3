# -*- coding: utf-8 -*-
# https://www.nowcoder.com/practice/376282a6682a4005973cde7b3df69584

MOD = 1000000007

def MatrixMul(a, b):
    r = [[0, 0], [0, 0]]
    r[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD
    r[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD
    r[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD
    r[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD
    return r


def QuickMatrixPower(A, n):
    if n == 1:
        return A
    Temp = QuickMatrixPower(A, n // 2)
    if n % 2 == 1:
        return MatrixMul(MatrixMul(Temp, Temp), A)
    return MatrixMul(Temp, Temp)


Term0 = 1
Term1 = 1
A = 1
B = 1
N = int(input())
if N <= 2:
    print(Term1 % MOD)
else:
    print(MatrixMul(QuickMatrixPower([[A, B], [1, 0]], N - 2), [[Term1, 1], [Term0, 1]])[0][0] % MOD)