# https://www.nowcoder.com/practice/181a1a71c7574266ad07f9739f791506

def f(a, L):
    b = set()
    for i in xrange(L):
        for j in xrange(i + 1, L + 1):
            k = a[i:j]
            if not k in b:
                b |= {k}
    return b

try:
    while 1:
        a, b = raw_input(), raw_input()
        L, L2 = len(a), len(b)
        s = f(a, L) & f(b, L2)
        Max = len(max(s,key=len))
        q = filter(lambda x:len(x) == Max, s)
        print min(q, key=a.index) if L < L2 else min(q, key=b.index)
except:
    pass