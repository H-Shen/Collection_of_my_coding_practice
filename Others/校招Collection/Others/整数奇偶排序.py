# https://www.nowcoder.com/practice/bbbbf26601b6402c9abfa88de5833163

try:
    while 1:
        L = map(int, raw_input().split())
        print ' '.join(map(str, sorted(list(filter(lambda x:x % 2 != 0, L)),reverse=True) + sorted(list(filter(lambda x:x % 2 == 0, L)))))
except:
    pass
