def MatrixMul(a, b):
    r = [[0, 0], [0, 0]]
    r[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0])
    r[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1])
    r[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0])
    r[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1])
    return r

def QuickMatrixPower(A, n):
    if n == 1:
        return A
    Temp = QuickMatrixPower(A, n // 2)
    if n % 2 == 1:
        return MatrixMul(MatrixMul(Temp, Temp), A)
    return MatrixMul(Temp, Temp)

def fib(n):
    if n == 0 or n == 1:
        return 1
    return MatrixMul(QuickMatrixPower([[1, 1],[1, 0]], n - 1),[[1, 1],[1, 1]])[0][0]


a = [fib(i) for i in xrange(80)]

try:
    while 1:
        start, end = map(int, raw_input().split())
        print sum(a[start - 1: end])
except:
    pass