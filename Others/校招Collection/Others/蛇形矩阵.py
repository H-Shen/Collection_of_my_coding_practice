# https://www.nowcoder.com/practice/649b210ef44446e3b1cd1be6fa4cab5e

try:
    while 1:
        n = input()
        a = [[0] * n for i in xrange(n)]

        valid = 1
        for k in xrange(n):
            for i in xrange(k + 1):
                a[k - i][i] = valid
                valid += 1

        for i in xrange(n):
            print ' '.join(map(str, filter(lambda x:x != 0, a[i])))
except:
    pass