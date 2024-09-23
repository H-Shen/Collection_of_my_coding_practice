# https://www.nowcoder.com/practice/dbace3a5b3c4480e86ee3277f3fe1e85

try:
    while 1:
        m = input()
        print '+'.join([str(pow(m, 2) - m + 1 + 2 * i) for i in xrange(m)])
except:
    pass