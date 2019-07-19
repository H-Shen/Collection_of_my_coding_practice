# https://www.nowcoder.com/practice/f89f96ea3145418b8e6c3eb75773f65a

try:
    while 1:
        s = raw_input()
        length = len(s)
        L = sorted([s[i:] for i in xrange(-1, -length - 1, -1)])
        for i in L:
            print i
except:
    pass