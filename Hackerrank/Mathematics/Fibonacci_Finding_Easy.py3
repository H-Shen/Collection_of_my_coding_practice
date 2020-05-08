def mul22(a, b):
    r = [[0, 0], [0, 0]]
    r[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % 1000000007
    r[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % 1000000007
    r[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % 1000000007
    r[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % 1000000007
    return r

def MatrixPow(A, n):
    if n == 1:
        return A
    k = MatrixPow(A, n // 2)
    if n % 2 == 1:
        return mul22(mul22(k,k), A)
    return mul22(k,k)

for i in range(int(input())):
    A, B, N = map(int,input().split())
    if N == 1:
        print(B % 1000000007)
    else:
        print(mul22(MatrixPow([[1, 1],[1, 0]], N - 1),[[B,1],[A,1]])[0][0] % 1000000007)
