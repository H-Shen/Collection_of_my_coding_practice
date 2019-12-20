# https://www.nowcoder.com/practice/dd0c6b26c9e541f5b935047ff4156309

def qsort(L, n):
    if n == 0:
        return []
    m, l, r, nl, nr = L[0], [], [], 0, 0
    for i in L[1:]:
        if i <= m:
            l.append(i)
            nl += 1
        else:
            r.append(i)
            nr += 1
    return qsort(l, nl) + [m] + qsort(r, nr)

try:
    while 1:
        n = input()
        L = map(int, raw_input().split())
        reverseBool = input()
        if reverseBool == 0:
            print ' '.join(map(str, qsort(L, n)))
        else:
            print ' '.join(map(str, qsort(L, n)[::-1]))
except:
    pass