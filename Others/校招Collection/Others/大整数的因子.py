# https://www.nowcoder.com/practice/3d6cee12fbf54ea99bb165cbaba5823d

try:
    while 1:
        c = int(raw_input())
        if c == -1:
            break
        result = [str(i) for i in xrange(2, 10) if c % i == 0]
        print 'none' if len(result) == 0 else ' '.join(result)
except:
    pass