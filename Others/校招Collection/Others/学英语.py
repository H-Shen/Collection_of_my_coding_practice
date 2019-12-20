# https://www.nowcoder.com/practice/1364723563ab43c99f3d38b5abef83bc

import re

table = {1: 'one', 2: 'two', 3: 'three', 4: 'four', 5: 'five',
         6: 'six', 7: 'seven', 8: 'eight', 9: 'nine', 10: 'ten',
         11: 'eleven', 12: 'twelve', 13: 'thirteen', 14: 'fourteen',
         15: 'fifteen', 16: 'sixteen', 17: 'seventeen', 18: 'eighteen',
         19: 'nineteen', 20: 'twenty', 30: 'thirty', 40: 'forty', 50: 'fifty',
         60: 'sixty', 70: 'seventy', 80: 'eighty', 90: 'ninety', 100: 'one hundred'}


def handle(n):
    global table
    if n <= 20:
        return table[n]
    if n <= 100 and n % 10 == 0:
        return table[n]
    if n < 100:
        return table[n // 10 * 10] + ' ' + table[n - n // 10 * 10]
    if n % 100 == 0:
        return table[n // 100] + ' hundred'
    if n - n // 100 * 100 <= 20 or (n - n // 100 * 100) % 10 == 0:
        return table[n // 100] + ' hundred ' + table[n - n // 100 * 100]
    return table[n // 100] + ' hundred ' + table[(n - n // 100 * 100) // 10 * 10] + ' ' + table[n - n // 10 * 10]

def printNum(n):
    if n == 0:
        return 'zero'
    else:
        bits = [0, 0, 0, 0]
        bits[0] = n // (10 ** 9)
        bits[1] = n // (10 ** 6) - bits[0] * 10 ** 3
        bits[2] = n // (10 ** 3) - bits[0] * 10 ** 6 - bits[1] * 10 ** 3
        bits[3] = n - bits[0] * 10 ** 9 - bits[1] * 10 ** 6 - bits[2] * 10 ** 3
        result = ''
        if bits[0] != 0:
            result = handle(bits[0]) + ' billion ' + result
        if bits[1] != 0:
            result = result + handle(bits[1]) + ' million '
        if bits[2] != 0:
            result = result + handle(bits[2]) + ' thousand '
        result += handle(bits[3])
        return result

def strToNum(s):
    # s is a string
    if len(s) > 9:
        return 'error'

    k = re.findall(r'^\d+$', s)
    if not (len(k) == 1 and k[0] == s):
        return 'error'

    s = printNum(int(s))

    #hundred and
    s = s.split()
    length = len(s)
    for i in xrange(length - 1):
        if s[i] == 'hundred' and s[i + 1] not in {'billion', 'million', 'thousand'}:
            s[i] = 'hundred and'

    return ' '.join(s)

try:
    while 1:
        print strToNum(raw_input())
except:
    pass