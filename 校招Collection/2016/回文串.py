# https://www.nowcoder.com/practice/655a43d702cd466093022383c24a38bf

try:
    while 1:
        a = raw_input()
        b = a + a[0]
        c = a[:-1]
        print 'YES' if (b == b[::-1] or c == c[::-1]) else 'NO'
except:
    pass