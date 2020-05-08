# -*- coding: utf-8 -*-

def getDigitalRoot(n):
    if n < 0:
        return getDigitalRoot(-n)
    return 1 + (n - 1) % 9

try:
    while True:
        n = int(input())
        print(getDigitalRoot(n))
except:
    pass
