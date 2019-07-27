import re

def hexFilter(s):
    if s[0] != '#':
        return False
    if len(s[1:]) != 3 and len(s[1:]) != 6:
        return False
    try:
        a = int(s[1:],base=16)
    except:
        return False
    else:
        return True

Flag = False
for i in range(int(input())):
    Input = input()
    if '{' in Input:
        Flag = True
        continue
    if '}' in Input:
        Flag = False
        continue
    if Flag == True:
        String = re.findall('#[a-zA-Z0-9]+',Input)
        if String != []:
            for j in range(len(String)):
                if  hexFilter(String[j]) == True:
                    print(String[j])
