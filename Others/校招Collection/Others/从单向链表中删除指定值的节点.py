# https://www.nowcoder.com/practice/f96cd47e812842269058d483a11ced4f

try:
    while 1:
        a = list()
        s = raw_input().split()
        Node = int(s[0])
        a.append(int(s[1]))
        k = 2
        for i in xrange(Node - 1):
            m, n = int(s[k]), int(s[k + 1])
            a.insert(a.index(n) + 1, m)
            k += 2
        a.remove(int(s[-1]))
        for i in a[:-1]:
            print i,
        print a[-1],
        print ''
except:
    pass