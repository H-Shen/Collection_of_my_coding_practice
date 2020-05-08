# https://open.kattis.com/problems/repeatingdecimal

from decimal import *

try:
    while 1:
        a, b, c = list(map(int, input().split()))
        ans = ""
        if a % b == 0:
            ans = str(a // b) + "." + c * '0'
        else:
            getcontext().prec = 10005
            s = str(Decimal(a) / Decimal(b))
            if len(s) != 10005:
                s = s + (10005 - len(s)) * '0'
            cnt = 0
            afterDecimal = False
            for i in range(len(s)):
                if s[i] == '.':
                    afterDecimal = True
                if cnt == c:
                    break
                ans = ans + s[i]
                if afterDecimal and s[i] != '.':
                    cnt += 1
        print(ans)
except:
    pass
