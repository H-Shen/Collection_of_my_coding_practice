# https://www.nowcoder.com/practice/4b1658fd8ffb4217bc3b7e85a38cfaf2

import re

try:
    while 1:
        print len(max(re.findall(r'1{1,}', bin(input())[2:]), key=len))
except:
    pass