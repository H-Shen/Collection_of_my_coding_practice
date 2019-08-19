from math import log
try:
    while 1:
        n = input()
        if n == 0:
            break
        elif n == 1:
            print 0
        elif n == 2 or n == 3:
            print 1
        else:
            k = int(log(n, 3))
            if pow(3, k) >= n:
                print k
            else:
                print k + 1
except:
    pass