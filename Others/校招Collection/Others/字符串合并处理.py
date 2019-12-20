# https://www.nowcoder.com/practice/d3d8e23870584782b3dd48f26cb39c8f

t = '0123456789abcdefABCDEF'
try:
    while 1:
        s = ''.join(raw_input().split())
        a, b = s[0::2], s[1::2]
        a, b = sorted(a), sorted(b)
        c = ""
        sign = True
        while (len(a) != 0 or len(b) != 0):
            if sign:
                c += a[0]
                del a[0]
                sign = False
            else:
                c += b[0]
                del b[0]
                sign = True
        length = len(c)
        d = ""
        for i in xrange(length):
            if c[i] in t:
                n = int(c[i], 16)
                n = bin(n)[2:]
                n = '0' * (4 - len(n)) + n
                d += hex(int(n[::-1], 2))[2:].upper()
            else:
                d += c[i]
        print d
except:
    pass