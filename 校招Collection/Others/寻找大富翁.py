# https://www.nowcoder.com/practice/38131e23663746a992581d45f16e7a86

try:
    while 1:
        n, m = map(int, raw_input().split())
        if n == m == 0:
            break
        L = sorted([int(i) for i in raw_input().split() if int(i) > 0], reverse=True)
        print ' '.join(map(str, L)) if m > len(L) else ' '.join(map(str, L)[:m])
except:
    pass