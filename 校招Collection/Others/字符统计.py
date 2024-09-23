# https://www.nowcoder.com/practice/c1f9561de1e240099bdb904765da9ad0

from collections import Counter
from string import ascii_letters, digits

a = ascii_letters + digits + ' '

try:
    while 1:
        s = raw_input()
        print ''.join(map(lambda z:z[0], sorted(filter(lambda x:x[0] in a, Counter(s).items()), key=lambda y:(y[1], -ord(y[0])), reverse=True)))
except:
    pass