# https://www.nowcoder.com/practice/04c0f21530994fbfa94887f1e3588e6a

try:
    while 1:
        n = input()
        L = map(int, raw_input().split())
        Max, Min = max(L), min(L)
        for i in xrange(n):
            if L[i] == Max:
                L[i] = Min
            elif L[i] == Min:
                L[i] = Max
        print ' '.join(map(str, L))
except:
    pass