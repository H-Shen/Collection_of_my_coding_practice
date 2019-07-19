# https://www.nowcoder.com/practice/ddec753f446e4ba4944e35378ba635c8

from decimal import Decimal, getcontext

getcontext().prec = 105

try:
    while 1:
        print str(Decimal(raw_input()) + Decimal(raw_input())).rstrip('0')
except:
    pass