# https://www.nowcoder.com/practice/98dc82c094e043ccb7e0570e5342dd1b

import re

def f(m, n, L):
    result = 0
    for i in xrange(L):
        for j in xrange(i + 1, L + 1):
            if re.match('.*' + m[i:j] + '.*', n):
                if result < j - i:
                    result = j - i
    return result

try:
    while 1:
        a, b = raw_input(), raw_input()
        if len(a) < len(b):
            print f(a, b, len(a))
        else:
            print f(b, a, len(b))
except:
    pass