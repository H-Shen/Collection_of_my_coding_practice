# https://www.nowcoder.com/practice/15e41630514445719a942e004edc0a5b

import re

try:
    while 1:

        table = []

        n = input()
        for i in xrange(n):
            a, b = map(int, raw_input().split())
            table.append(['', a, b])

        expr = raw_input()
        pos = 0
        for i in expr:
            if i != '(' and i != ')':
                table[pos][0] = i
                pos += 1

        flop = 0
        result = re.findall(r'\(\w+\)', expr)
        while result != []:
            for j in result:
                length = len(table)
                pos1 = -1
                pos2 = -1
                for k in xrange(length):
                    if table[k][0] == j[1]:
                        pos1 = k
                    if table[k][0] == j[2]:
                        pos2 = k
                    if pos1 != -1 and pos2 != -1:
                        break
                flop += table[pos1][1] * table[pos1][2] * table[pos2][2]
                table[pos1][2] = table[pos2][2]
                expr = expr.replace(j, table[pos1][0])
                result = re.findall(r'\(\w+\)', expr)

        print flop

except:
    pass