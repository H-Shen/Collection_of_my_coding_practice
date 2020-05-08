# https://open.kattis.com/problems/wertyu

a = "1234567890-=WERTYUIOP[]\SDFGHJKL;'XCVBNM,./ "
b = "‘1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,. "
d = dict(zip(a, b))

try:
    while 1:
        s = input()
        ans = ""
        for i in range(len(s)):
            if s[i] in d:
                ans = ans + d[s[i]]
            else:
                ans = ans + s[i]
        print(ans)
except:
    pass
