# https://www.nowcoder.com/practice/7385949943264a9fa4348cbd43e6e00c

try:
    while 1:
        for case in xrange(1):
            a = zip(*[map(int, raw_input().split()) for k in range(4)])
            b = map(lambda x:sorted(x)[-2:], a)
            for i in range(5):
                if a[i].index(b[i][0]) > a[i].index(b[i][1]):
                    b[i][0], b[i][1] = b[i][1], b[i][0]
            c = zip(*b)
            for j in c:
                print ' '.join(map(str, j)) + ' '
except:
    pass