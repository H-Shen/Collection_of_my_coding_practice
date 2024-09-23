def expr(r, i):
    r = "%.1f" % r
    i = "%.1f" % i
    if (float(i) >= 0):
        return "(" + r + "+" + i + "i)"
    return "(" + r + i + "i)"

def to_string(a):

    r = float("%.1f" % a.real)
    i = float("%.1f" % a.imag)

    if (r == 0.0 and i == 0.0):
        return "0.0"
    if (r == 0.0 and i != 0.0):
        return str(i) + "i"
    if (r != 0.0 and i == 0.0):
        return str(r)

    result = ""
    if (i > 0):
        result = str(r) + "+" + str(i) + "i"
    else:
        result = str(r) + str(i) + "i"

    if ('(' in result):
        result = result.lstrip('(').rstrip(')')

    return result

r0, i0, r1, i1 = list(map(float, input().split()))
c0, c1 = complex(r0, i0), complex(r1, i1)

a = c0 + c1
b = c0 - c1
c = c0 * c1
d = c0 / c1

expr0 = expr(r0, i0)
expr1 = expr(r1, i1)

print(expr0 + " + " + expr1 + " = " + to_string(a))
print(expr0 + " - " + expr1 + " = " + to_string(b))
print(expr0 + " * " + expr1 + " = " + to_string(c))
print(expr0 + " / " + expr1 + " = " + to_string(d))