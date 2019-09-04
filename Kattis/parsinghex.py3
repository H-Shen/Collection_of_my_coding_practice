# -*- coding: utf-8 -*-
# https://open.kattis.com/problems/parsinghex

upperbound = int('0xffffffff', 16)
legalCharset = set('0123456789abcdefABCDEF')

from collections import deque

try:
    while True:
        s = deque(input())
        hasAns = False
        while (len(s) > 2):

            if s[0] == '0' and (s[1] == 'x' or s[1] == 'X'):
                number = s[0] + s[1]
                s.popleft()
                s.popleft()
                while True:
                    if len(s) == 0:
                        hasAns = True
                        break
                    if s[0] not in legalCharset:
                        hasAns = True
                        break
                    if int(number + s[0], 16) > upperbound:
                        hasAns = True
                        break
                    number += s[0]
                    s.popleft()
            else:
                s.popleft()

            if hasAns:
                print(number, int(number, 16))
                hasAns = False
except:
    pass
