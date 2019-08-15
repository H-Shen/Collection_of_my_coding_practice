# -*- coding: utf-8 -*-
# https://open.kattis.com/problems/addingwords
#
variableTable = dict()
try:
    while True:
        s = input().split()
        if s[0] == 'clear':
            variableTable.clear()
        elif s[0] == 'def':
            variableTable[s[1]] = int(s[2])
        else:
            expression = ' '.join(s[1:]) + ' '
            expressionWithValueReplaced = ""
            hasAns = True
            for i in s[1:-1]:
                if (i == "+" or i == "-"):
                    expressionWithValueReplaced += i
                elif (i not in variableTable):
                    hasAns = False
                    break
                else:
                    expressionWithValueReplaced += str(variableTable[i])
            if hasAns:
                resultInDict = False
                result = eval(expressionWithValueReplaced)
                for key, value in variableTable.items():
                    if value == result:
                        resultInDict = True
                        print(expression + key)
                        break
                if not resultInDict:
                    print(expression + "unknown")
            else:
                print(expression + "unknown")
except:
    pass

