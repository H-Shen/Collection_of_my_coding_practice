# https://www.nowcoder.com/practice/ef7f264886a14fdf8a6ed3ac008a23c8

def triangles():
    L = [1]
    while 1:
        yield L
        L.append(0)
        n = len(L)
        L = [L[i - 1] + L[i] for i in xrange(n)]

try:
    while 1:
        generator = triangles()
        next(generator)
        for i in xrange(input() - 1):
            print ' '.join(map(str, next(generator)))
except:
    pass