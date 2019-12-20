# https://www.nowcoder.com/practice/9ef1046e746248fe93751e37126bb9e0

def fibBool(n):
    a = n * n * 5 + 4
    b = n * n * 5 - 4
    return (a ** 0.5 % 1 == 0 or b ** 0.5 % 1 == 0)

def subString(s):
    L = len(s)
    return set([s[i:j] for i in xrange(L) for j in xrange(i + 1, L + 1)])

try:
    while 1:
        s = raw_input()
        sub = subString(s)
        output = sorted(filter(lambda x:fibBool(len(set(x))) is True, sub))
        for i in output:
            print i
except:
    pass