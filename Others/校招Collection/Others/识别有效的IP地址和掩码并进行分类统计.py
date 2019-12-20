# https://www.nowcoder.com/practice/de538edd6f7e4bc3a5689723a7435682

import re
pattern = re.compile(r'^\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}$')
pattern2 = re.compile(r'^1{1,}0{1,}$')

def legal(s):
    global pattern
    a = pattern.findall(s)
    if len(a) == 1:
        b = a[0].split('.')
        for i in b:
            if not (0 <= int(i) <= 255 and str(int(i)) == i):
                return False
        return True
    return False

def mask(s):
    global pattern2
    if not legal(s):
        return False
    a = ''.join(map(lambda x: bin(int(x))[2:].zfill(8), s.split('.')))
    b = pattern2.findall(a)
    if (len(b) == 1 and b[0]) == a:
        return True
    return False

def assortIP(s):
    a, b, c, d = map(int, s.split('.'))

    if (a == 10 and 0 <= b <= 255 and 0 <= c <= 255 and 0 <= d <= 255):
        return 'PA'
    if (a == 172 and 16 <= b <= 31 and 0 <= c <= 255 and 0 <= d <= 255):
        return 'PB'
    if (a == 192 and b == 168 and 0 <= c <= 255 and 0 <= d <= 255):
        return 'PC'
    if (1 <= a <= 126 and 0 <= b <= 255 and 0 <= c <= 255 and 0 <= d <= 255):
        return 'A'
    if (128 <= a <= 191 and 0 <= b <= 255 and 0 <= c <= 255 and 0 <= d <= 255):
        return 'B'
    if (192 <= a <= 223 and 0 <= b <= 255 and 0 <= c <= 255 and 0 <= d <= 255):
        return 'C'
    if (224 <= a <= 239 and 0 <= b <= 255 and 0 <= c <= 255 and 0 <= d <= 255):
        return 'D'
    if (240 <= a <= 255 and 0 <= b <= 255 and 0 <= c <= 255 and 0 <= d <= 255):
        return 'E'

try:
    A, B, C, D, E, P, Err = [0] * 7

    while 1:
        s = raw_input()
        s = s.split('~')

        if (not legal(s[0]) or not mask(s[1])):
            Err += 1
        else:
            if assortIP(s[0]) == 'A':
                A += 1
            if assortIP(s[0]) == 'B':
                B += 1
            if assortIP(s[0]) == 'C':
                C += 1
            if assortIP(s[0]) == 'D':
                D += 1
            if assortIP(s[0]) == 'E':
                E += 1
            if assortIP(s[0]) == 'PA':
                P += 1
                A += 1
            if assortIP(s[0]) == 'PB':
                P += 1
                B += 1
            if assortIP(s[0]) == 'PC':
                P += 1
                C += 1

except:
    print A, B, C, D, E, Err, P
    pass