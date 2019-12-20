# https://www.nowcoder.com/practice/119bcca3befb405fbe58abe9c532eb29

import re
KeySet = {'A', 'W', 'S', 'D'}

def move(loc, ins):
    a = re.findall('\w\d+', ins)
    if len(a) == 1 and a[0] == ins and a[0][0] in KeySet:
        if a[0][0] == 'A':
            loc[0] -= int(ins[1:])
        elif a[0][0] == 'S':
            loc[1] -= int(ins[1:])
        elif a[0][0] == 'W':
            loc[1] += int(ins[1:])
        else:
            loc[0] += int(ins[1:])
        return loc
    return loc

try:
    while 1:
        loc = [0, 0]
        trail = raw_input().split(';')
        for i in trail:
            loc = move(loc, i)
        print str(loc[0]) + ',' + str(loc[1])
except:
    pass