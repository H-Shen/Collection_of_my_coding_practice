# https://www.nowcoder.com/practice/7bdc346ca39841f6a05f73d98477621d

def transform(n):
    return ''.join(map(lambda x:bin(int(x, 16))[2:].zfill(4), hex(n)[2:].zfill(4)))

def shiftBool(str_a, str_b):
    len_a = len(str_a)
    table = {str_a[i:] + str_a[:i] for i in xrange(1, len_a + 1)}
    return str_b in table

try:
    while 1:
        a, b = map(int, raw_input().split())
        print 'YES' if shiftBool(transform(a), transform(b)) else 'NO'
except:
    pass