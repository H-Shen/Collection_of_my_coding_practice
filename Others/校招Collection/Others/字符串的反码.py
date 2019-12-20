# https://www.nowcoder.com/practice/01b7dae14d1b464db5f9259e90d9a35e

from string import ascii_lowercase, ascii_uppercase

Lower = dict(zip(ascii_lowercase, ascii_lowercase[::-1]))
Upper = dict(zip(ascii_uppercase, ascii_uppercase[::-1]))

def convert(s):
    res = ""
    for i in s:
        if i.isupper():
            res += Upper[i]
        elif i.islower():
            res += Lower[i]
        else:
            res += i
    return res

try:
    while 1:
        a = raw_input()
        if a == '!':
            break
        print convert(a)
except:
    pass