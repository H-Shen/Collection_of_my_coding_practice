# https://www.nowcoder.com/practice/d9162298cb5a437aad722fccccaae8a7

for j in xrange(2):
    s = raw_input()
    L = len(s)
    for i in xrange(0, L, 8):
        print '{:0<8s}'.format(s[i:i + 8])