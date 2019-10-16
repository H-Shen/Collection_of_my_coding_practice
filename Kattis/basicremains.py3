# -*- coding: utf-8 -*-
# https://open.kattis.com/problems/basicremains

def decimalToAny(num, n):
    global  baseStr
    new_num_str = ""
    while num != 0:
        remainder = num % n
        remainder_string = str(remainder)
        new_num_str = remainder_string+new_num_str
        num = num // n
    if new_num_str == "":
        new_num_str = "0"
    return new_num_str

while True:
    A = input().split()
    if A[0] == '0':
        break

    b = int(A[0])
    p = int(A[1], b)
    m = int(A[2], b)

    if A[1] == "0" or A[2] == "0":
        print(A[1])
    else:
        print(decimalToAny(p % m, b))
