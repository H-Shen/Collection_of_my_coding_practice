# https://www.nowcoder.com/practice/57f0f528bff149be9580af66f6292430

try:
    while 1:
        _ = input()
        a = map(int, raw_input().split())
        maxVal = max(a)
        del a[a.index(maxVal)]
        print maxVal
        print -1 if a == [] else ' '.join(map(str, sorted(a)))
except:
    pass