# https://www.nowcoder.com/practice/b3d9203523714e29838e5ca3b49727fc

try:
    while 1:
        s = raw_input()
        a = len(s)
        if a <= 76:
            print s
        else:
            n = a / 76
            m = a % 76
            for i in xrange(n):
                print s[76 * i:76 * (i + 1)]
            if m != 0:
                print s[-m:]
        print ''
except:
    pass