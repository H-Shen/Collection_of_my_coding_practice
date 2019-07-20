# https://www.nowcoder.com/practice/52d382c2a7164767bca2064c1c9d5361

def score(s):
    result, length, upper, lower, digit, other = [0] * 6
    for i in s:
        if i.isdigit():
            digit += 1
        elif i.isupper():
            upper += 1
        elif i.islower():
            lower += 1
        else:
            other += 1
        length += 1

    if length <= 4:
        result += 5
    elif length <= 7:
        result += 10
    else:
        result += 25

    if (upper == 0 and lower != 0) or  (lower == 0 and upper != 0):
        result += 10
    elif (upper != 0 and lower != 0):
        result += 20

    if digit == 1:
        result += 10
    elif digit >= 2:
        result += 20

    if other == 1:
        result += 10
    elif other > 1:
        result += 25

    if (upper != 0 and lower == 0 and digit != 0 and other == 0):
        result += 2
    elif (lower != 0 and upper == 0 and digit != 0 and other == 0):
        result += 2
    elif (lower != 0 and upper == 0 and digit != 0 and other != 0):
        result += 3
    elif (upper != 0 and lower == 0 and digit != 0 and other != 0):
        result += 3
    elif (upper != 0 and lower != 0 and digit != 0 and other != 0):
        result += 5

    if result >= 90:
        return 'VERY_SECURE'
    elif result >= 80:
        return 'SECURE'
    elif result >= 70:
        return 'VERY_STRONG'
    elif result >= 60:
        return 'STRONG'
    elif result >= 50:
        return 'AVERAGE'
    elif result >= 25:
        return 'WEAK'
    else:
        return 'VERY_WEAK'

try:
    while 1:
        print score(raw_input())
except:
    pass


