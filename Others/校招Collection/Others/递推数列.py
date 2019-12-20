# https://www.nowcoder.com/practice/d0e751eac618463bb6ac447369e4aa25

def MatrixMul(a, b):
    r = [[0, 0], [0, 0]]
    r[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) % 10000
    r[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % 10000
    r[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % 10000
    r[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % 10000
    return r

def QuickMatrixPower(A, n):
    if n == 1:
        return A
    Temp = QuickMatrixPower(A, n / 2)
    if n % 2 == 1:
        return MatrixMul(MatrixMul(Temp, Temp), A)
    return MatrixMul(Temp, Temp)
try:
    while 1:
        Term0, Term1, A, B, N = map(int, raw_input().split())
        if N == 1:
            print Term1 % 10000
        else:
            print MatrixMul(QuickMatrixPower([[A, B],[1, 0]], N - 1),[[Term1, 1],[Term0, 1]])[0][0] % 10000
except:
    pass