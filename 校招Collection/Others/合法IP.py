# https://www.nowcoder.com/practice/995b8a548827494699dc38c3e2a54ee9

import re

try:
    while 1:
        s = raw_input()
        a = re.findall('^\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}$', s)
        if len(a) == 1 and a[0] == s and len(filter(lambda x:x <= 255, map(int, s.split('.')))) == 4:
            print 'YES'
        else:
            print 'NO'
except:
    pass