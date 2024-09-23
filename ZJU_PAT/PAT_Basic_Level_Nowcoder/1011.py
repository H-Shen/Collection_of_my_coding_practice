isPrime = lambda n : False if any([bool(n % i == 0) for i in xrange(2, int(n))]) else True

table = set([n for n in xrange(-39, 50) if not isPrime(pow(n, 2) + n + 41)])

try:
    while 1:

        x, y = map(int, raw_input().split())

        if x == y == 0:
            continue
        Flag = 0
        a = xrange(x, y + 1)
        for i in table:
            if i in a:
                print "Sorry"
                Flag = 1
                break
        if Flag == 0:
            print "OK"

except:
    pass