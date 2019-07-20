# https://www.nowcoder.com/practice/31e539ab08f949a8bece2a7503e9319a

def matrixMul(a, b, n):
    result = [[0] * n for i in xrange(n)]
    for i in xrange(n):
        for j in xrange(n):
            result[i][j] = sum([a[i][k] * b[k][j] for k in xrange(n)])
    return result

try:
    while 1:
        T = 1
        for i in xrange(T):
            n, k = map(int, raw_input().split())
            mat = []
            for j in xrange(n):
                mat.append(map(int, raw_input().split()))
            current = matrixMul(mat, mat, n)
            if k - 1 != 0:
            	for j in xrange(k - 2):
                	current = matrixMul(current, mat, n)
            else:
                current = mat
            for row in xrange(n):
                print ' '.join(map(str,current[row]))
except:
    pass