import math

def vectorDifference(A, B):
    '''A, B are lists.
    Return a list.
    '''
    d1 = B[0] - A[0]
    d2 = B[1] - A[1]
    d3 = B[2] - A[2]

    return [d1, d2, d3]

def vectorCrossProduct(A, B):
    '''A, B are lists.
    Return a list.
    '''
    d1 = A[1] * B[2] - B[1] * A[2]
    d2 = B[0] * A[2] - A[0] * B[2]
    d3 = A[0] * B[1] - B[0] * A[1]

    return [d1, d2, d3]

def vectorDotProduct(A, B):
    '''A, B are lists.
    Return a list.
    '''
    d1 = A[0] * B[0]
    d2 = A[1] * B[1]
    d3 = A[2] * B[2]

    return d1 + d2 + d3

def vectorLength(A):
    a = A[0] ** 2 + A[1] ** 2 + A[2] ** 2
    return a ** (1/2)

def cosphi(A, B, C, D):
    AB = vectorDifference(A, B)
    BC = vectorDifference(B, C)
    CD = vectorDifference(C, D)
    X = vectorCrossProduct(AB, BC)
    Y = vectorCrossProduct(BC, CD)
    XY = vectorDotProduct(X, Y)
    LX = vectorLength(X)
    LY = vectorLength(Y)

    return XY / (LX * LY)

A = list(map(float,input().strip().split()))
B = list(map(float,input().strip().split()))
C = list(map(float,input().strip().split()))
D = list(map(float,input().strip().split()))

result = cosphi(A, B, C, D)
result = math.acos(result)
result = math.degrees(result)
result = '%.2f' % result
print(result)