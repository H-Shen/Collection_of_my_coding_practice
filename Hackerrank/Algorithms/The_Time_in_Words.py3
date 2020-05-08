#!/bin/python3

import sys


table = {1:'one',2:'two',3:'three',4:'four',
         5:'five',6:'six',7:'seven',8:'eight',
         9:'nine',10:'ten',11:'eleven',12:'twelve',
         13:'thirteen',14:'fourteen',15:'fifteen',
         16:'sixteen',17:'seventeen',18:'eighteen',
         19:'nineteen',20:'twenty',30:'thirty',40:'forty',
         50:'fifty'}

def handle(n):
    global table
    if n <= 20:
        return table[n]
    if n <= 100 and n % 10 == 0:
        return table[n]
    return table[n // 10 * 10] + ' ' + table[n - n // 10 * 10]

h = int(input().strip())
m = int(input().strip())

if m == 0:
    print(table[h] + " o' clock")
elif m == 30:
    print("half past " + table[h])
elif m == 45:
    print("quarter to " + table[h + 1])
elif m == 15:
    print("quarter past " + table[h])
elif m > 30:
    print(handle(60 - m) + " minutes to " + table[h + 1])
elif m == 1:
    print("one minute past " + table[h])
else:
    print(handle(m) + " minutes past " + table[h])
