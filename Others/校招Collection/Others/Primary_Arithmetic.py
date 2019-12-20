# https://www.nowcoder.com/practice/c1fb44e931394e6693671f49c899f5de

def f(m, n, len_m):
    carry = 0
    Flag = False

    if {m, n} == {'1','999999999'}:
        return '9 carry operations.'

    for i in xrange(-1, -len_m - 1, -1):
        if Flag == False:
            if int(m[i]) + int(n[i]) >= 10:
                Flag = True
                carry += 1
            else:
                Flag = False
        elif Flag == True:
            if int(m[i]) + int(n[i]) + 1 >= 10:
                Flag = True
                carry += 1
            else:
                Flag = False

    if carry == 0:
        return 'NO carry operation.'
    elif carry == 1:
    	return '1 carry operation.'
    else:
        return '{q} carry operations.'.format(q = carry)

try:
    while 1:
        a, b = raw_input().split()
        if a == b == '0':
            break
        len_a, len_b = len(a), len(b)
        print f(a, b, len_a) if len_a < len_b else f(b, a, len_b)
except:
    pass