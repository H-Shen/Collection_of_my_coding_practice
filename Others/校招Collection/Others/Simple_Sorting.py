# https://www.nowcoder.com/practice/139761e0b59a405786898b7f2db9423f

try:
    while 1:
        n = input()
        print ' '.join(map(str, sorted(set(map(int, raw_input().split())))))
except:
    pass