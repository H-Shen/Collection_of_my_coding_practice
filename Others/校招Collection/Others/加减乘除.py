# https://www.nowcoder.com/practice/fdc56f9b00b34c70ad36c61ef89e3fc3

from math import factorial

try:
    while 1:
        try:
            expr = raw_input()
            print eval(expr)
        except ZeroDivisionError:
            print 'error'
        except SyntaxError:
            print factorial(int(expr.split()[0]))
except:
    pass