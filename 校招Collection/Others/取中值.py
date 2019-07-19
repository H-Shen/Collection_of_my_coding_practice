# https://www.nowcoder.com/practice/d69e75bb224e4a7785a02b2acc0821c4

try:
    while 1:
        t = input()
        for i in xrange(t):
            n, m = map(int, raw_input().split())
            N = map(int, raw_input().split())
            M = map(int, raw_input().split())
            a, b, c, d = map(int, raw_input().split())
            result = N[a:b] + M[c:d]
            length = (b - a - 1) + (d - c - 1)
            if length % 2 != 0:
                print result[(length - 1) / 2]
            else:
                print result[length / 2 - 1]
except:
    pass