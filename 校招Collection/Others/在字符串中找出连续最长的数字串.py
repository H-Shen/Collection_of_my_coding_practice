# https://www.nowcoder.com/practice/2c81f88ecd5a4cc395b5308a99afbbec

import re

try:
    while 1:
        a = re.findall('\d+', raw_input())
        n = len(max(a, key=len))
        print ''.join(filter(lambda x:len(x) == n, a)) + ',' + str(n)
except:
    pass