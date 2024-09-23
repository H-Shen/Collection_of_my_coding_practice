# https://www.nowcoder.com/practice/647fc23dc4e147328cc484e3aeb6cc2a

def p(n, m):
    result = 0
    for i in xrange(n - m + 1, n + 1):
        a = i
        while a % 2 == 0:
            result += 1
            a = a >> 1
    return result

try:
    while 1:
        n, m = map(int, raw_input().split())
        if n == 0:
            break
        else:
            print p(n, m)
except:
    pass
