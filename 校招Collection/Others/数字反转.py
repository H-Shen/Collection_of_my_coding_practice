# https://www.nowcoder.com/practice/2687c5c174cb4f938bdae01f0a19490c

try:
    while 1:
        a, b = raw_input().split()
        s1 = int(a[::-1]) + int(b[::-1])
        s2 = int(str(int(a) + int(b))[::-1])
        print 'NO' if s1 != s2 else int(a) + int(b)
except:
    pass