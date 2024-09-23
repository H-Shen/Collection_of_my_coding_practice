# -*- coding:utf-8 -*-

# https://www.nowcoder.com/practice/73f21c4e681f44be9517f215b7652eb8

def flipSign(a):
    if a > 0:
        temp = '-' + str(a)
        return eval(temp)
    else:
        return eval(str(a)[1:])

def Mul(a, b):
    s, flag = 0, 0
    if a < 0 and b < 0:
        a, b = flipSign(a), flipSign(b)
    elif a < 0 and b > 0:
        a, flag = flipSign(a), 1
    elif a > 0 and b < 0:
        b, flag = flipSign(b), 1
    for i in xrange(b):
        s += a
    return s if flag == 0 else flipSign(s)

def Div(a, b):
    s, flag = 0, 0
    if a < 0 and b < 0:
        a, b = flipSign(a), flipSign(b)
    elif a < 0 and b > 0:
        a, flag = flipSign(a), 1
    elif a > 0 and b < 0:
        b, flag = flipSign(b), 1
    if a != 0:
        while a >= b:
            a -= b
            s += 1
    return s if flag == 0 else flipSign(s)

def Sub(a, b):
    return a if b == 0 else a + flipSign(b)

class AddSubstitution:
    def calc(self, a, b, t):
        if t == 1:
            return Mul(a, b)
        elif t == 0:
            return Div(a, b)
        return Sub(a, b)