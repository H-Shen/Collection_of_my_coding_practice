# https://www.nowcoder.com/practice/5928127cc6604129923346e955e75984

def skew(n):
    a = list(map(int, str(n)))
    L = len(a)
    return sum([(a[i] << (L - i)) - a[i] for i in xrange(L)])
try:
    while 1:
        print skew(input())
except:
    pass