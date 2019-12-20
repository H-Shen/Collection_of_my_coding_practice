# https://www.nowcoder.com/practice/7fd72f8ac7964ba3b8baa8735246e1f1

def ExtremePoint(L, n):
    result = []
    if L[0] != L[1]:
        result.append(0)
    for i in xrange(1, n - 1):
        if (L[i] < L[i - 1] and L[i] < L[i + 1]) or (L[i] > L[i - 1] and L[i] > L[i + 1]):
            result.append(i)
    if L[-1] != L[-2]:
        result.append(n - 1)
    return ' '.join(map(str, result))

try:
    while 1:
        n = input()
        Arr = map(int, raw_input().split())
        print ExtremePoint(Arr, n)
except:
    pass