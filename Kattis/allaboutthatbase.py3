# -*- coding: utf-8 -*-
# https://open.kattis.com/problems/allaboutthatbase
#
# return true if the string s includes '1' only
def f(s):
    tempSet = set(s)
    return len(tempSet) == 1 and '1' in tempSet

# pre
a = list('123456789abcdefghijklmnopqrstuvwxyz0')
baseToNotation = dict()
for i in range(len(a)):
    baseToNotation[i + 1] = a[i]
    
T = int(input())
for case in range(T):

    # input
    X, op, Y, _, Z = input().split()
    
    # process
    result = ""
    for i in range(1, 36):
        
        # special handle base 1
        if i == 1:
            if f(X) and f(Y) and f(Z):
                X_ = len(X)
                Y_ = len(Y)
                Z_ = len(Z)
            else:
                continue
        
        # handle base from 2-37
        else:
            try:
                X_ = int(X, i)
                Y_ = int(Y, i)
                Z_ = int(Z, i)
            except:
                continue
        
        # judge if the expression is correct
        if op == '+':
            if X_ + Y_ == Z_:
                result += baseToNotation[i]
        elif op == '-':
            if X_ - Y_ == Z_:
                result += baseToNotation[i]
        elif op == '*':
            if X_ * Y_ == Z_:
                result += baseToNotation[i]
        elif op == '/':
            if X_ // Y_ == Z_ and X_ % Y_ == 0:
                result += baseToNotation[i]
        
    # output
    if result == "":
        print("invalid")
    else:
        print(result)
