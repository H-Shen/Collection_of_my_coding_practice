#!/bin/python3

import sys, re

pat1 = re.compile('h.*a.*c.*k.*e.*r.*r.*a.*n.*k')

r1 = re.compile

q = int(input().strip())
for a0 in range(q):
    s = input().strip()
    # your code goes here
    if pat1.findall(s):
        print('YES')
    else:
        print('NO')
