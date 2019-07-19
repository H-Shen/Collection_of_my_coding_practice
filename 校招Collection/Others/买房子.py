# https://www.nowcoder.com/practice/a4b46b53773e4a8db60b5f7629ce03e9

try:
    while 1:
        N, K = map(int, raw_input().strip().split())
        Flag = 0
        for n in xrange(1, 22):
            if N * n >= 200 * (1 + K / 100.0) ** (n - 1):
                Flag = 1
                break
        print n if Flag == 1 else 'Impossible'
except:
    pass