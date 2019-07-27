import re

def sieve(num):
    if num.count('.') != 1:
        return False

    k = num.index('.')
    str1 = num[:k]
    str2 = num[(k + 1):]

    if len(str2) < 1:
        return False

    if ''.join(re.findall('[0-9]',str2)) != str2:
        return False

    if str1.count('+') == 1 and str1.index('+') == 0:
        if len(str1) == 1:
            return True
        elif ''.join(re.findall('[0-9]',str1[1:])) == str1[1:]:
            return True
        else:
            return False

    if str1.count('-') == 1 and str1.index('-') == 0:
        if len(str1) == 1:
            return True
        elif ''.join(re.findall('[0-9]',str1[1:])) == str1[1:]:
            return True
        else:
            return False

    if str1 == '':
        return True

    if ''.join(re.findall('[0-9]',str1)) == str1:
        return True

    return False

t = int(input())
for i in range(t):
    num = input()
    print(sieve(num))
