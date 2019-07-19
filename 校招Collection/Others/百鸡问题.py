# https://www.nowcoder.com/practice/01d161052db64c249a47fc723b4fd5db

try:
    while 1:
        n = input()
        for x in xrange(101):
            for y in xrange(101):
                if 14 * x + 8 * y <= 3 * n - 100:
                    print 'x={a},y={b},z={c}'.format(a = x, b = y, c = 100 - x - y)
except:
    pass