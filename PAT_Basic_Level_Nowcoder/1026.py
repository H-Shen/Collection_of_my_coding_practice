from decimal import Decimal, getcontext
getcontext().prec=1005

try:
    while 1:
        a, b, n = map(int, raw_input().split())
        result = str(Decimal(a) / Decimal(b))
        result = result.split('.')
        result = result[0] + '.' + result[1][:n].ljust(n, '0')
        print result
except:
    pass