# https://www.nowcoder.com/practice/c4f11ea2c886429faf91decfaf6a310b

try:
    while 1:
        n, N, m, M = input(), map(int, raw_input().split()), input(), map(int, raw_input().split())
        print ''.join(map(str, sorted(set(N) | set(M))))
except:
    pass