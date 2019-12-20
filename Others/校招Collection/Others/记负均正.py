# https://www.nowcoder.com/practice/6abde6ffcc354ea1a8333836bd6876b8

try:
    while 1:
        a, b, n, t, L  = 0, 0, 0, input(), map(int, raw_input().split())
        for s in L:
            if s < 0:
                a += 1
            if s > 0:
                b += s
                n += 1
        c = (b * 1.0) / n
        c = int(c) if c % 1 == 0 else '%.1f' % c
        print a, c
except:
    pass