# -*- coding: utf-8 -*-
# https://open.kattis.com/problems/whichbase
#
T = int(input())
for i in range(T):
    case, number = input().split()

    try:
        octal = int(number, 8)
    except:
        octal = 0

    decimal = int(number, 10)
    hexOutput = int(number, 16)
    print(case + ' ' + str(octal) + ' ' + str(decimal) + ' ' + str(hexOutput))
