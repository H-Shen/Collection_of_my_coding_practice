# https://www.nowcoder.com/practice/e8cee01f2d834fa9ba3479fafe492b65

try:
    while 1:
        L = map(int, raw_input().split())
        result, l = 0, len(L)
        for i in xrange(l):
            if L[i] <= 100:
                a, CurrentIndex = L[i], i
                break
        for j in L[CurrentIndex + 1:]:
            if j < a:
                result += j
        print result
except:
    pass