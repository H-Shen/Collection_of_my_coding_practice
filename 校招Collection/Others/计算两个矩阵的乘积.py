# https://www.nowcoder.com/practice/ed6552d03e624ba58d16af6d57e1c3e9

def Matrix(A, B):
    x1, x2, x3 = A[0]
    x4, x5, x6 = A[1]
    y1, y2 = B[0]
    y3, y4 = B[1]
    y5, y6 = B[2]
    z1 = x1 * y1 + x2 * y3 + x3 * y5
    z2 = x1 * y2 + x2 * y4 + x3 * y6
    z3 = x4 * y1 + x5 * y3 + x6 * y5
    z4 = x4 * y2 + x5 * y4 + x6 * y6
    return [[z1, z2], [z3, z4]]

try:
    while 1:
        A, B = [], []
        for i in xrange(2):
            A.append(map(int, raw_input().split()))
        for j in xrange(3):
            B.append(map(int, raw_input().split()))
        result = Matrix(A, B)
        for k in result:
            print ' '.join(map(str, k)) + ' '
except:
    pass