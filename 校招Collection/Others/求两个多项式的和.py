# https://www.nowcoder.com/practice/a9901ba9163549a590d1d1c245f14d2a

try:
    while 1:
        a, b = [map(int, raw_input().split()[1:]) for i in xrange(2)]
        Length_a, Length_b = len(a), len(b)
        A = dict([[a[i + 1], a[i]] for i in xrange(0, Length_a, 2)])
        for i in xrange(0, Length_b, 2):
            A[b[i + 1]] = A[b[i + 1]] + b[i] if b[i + 1] in A else b[i]
        result = filter(lambda y:y[0] != 0, map(lambda x: x[::-1], A.items()))
        result = sorted(result, key=lambda x: x[1], reverse=True)
        result = eval(str(result).replace('(','').replace(')',''))
        print ' '.join(map(str, result))
except:
    pass