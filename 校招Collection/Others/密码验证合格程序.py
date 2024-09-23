# https://www.nowcoder.com/practice/184edec193864f0985ad2684fbc86841

import re

try:
    while 1:
        input = raw_input()
        b0 = re.findall(r'(.{3,}).*\1', input)
        b1 = re.findall(r'\d', input)
        b2 = re.findall(r'[A-Z]', input)
        b3 = re.findall(r'[a-z]', input)
        b4 = re.findall(r'[^0-9A-Za-z]', input)
        print 'OK' if ([b1, b2, b3, b4].count([]) <= 1 and b0 == [] and len(input) > 8) else 'NG'
except:
    pass