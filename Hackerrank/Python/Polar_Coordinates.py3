import cmath

a = complex(input())
r1 = abs(a)
r2 = cmath.phase(a)

def roundec(a,b):

    import decimal
    decimal.getcontext().rounding = decimal.ROUND_HALF_UP
    a = str(a)
    c = decimal.Decimal(a,decimal.getcontext())
    d = float(c.__round__(b))
    return d

r1 = roundec(r1, 3)
r2 = roundec(r2, 3)

print(r1)
print(r2)
