import re
import string

t = int(input())
for i in range(t):
    result = input()
    name,addr = result.split()
    Flag = 0

    if addr.count('@') == 1:


        L = len(addr)
        addr = addr[1:(L - 1)]
        para1 = addr.index('@')
        stag1 = addr[:para1]
        stag2_3 = addr[(para1 + 1):]

        if stag2_3.count('.') == 1:

            para2 = stag2_3.index('.')
            stag2 = stag2_3[:para2]
            stag3 = stag2_3[(para2 + 1):]

            if 1 <= len(stag3) <= 3:
                if ''.join(re.findall("[a-zA-Z]", stag2)) == stag2 and \
                   ''.join(re.findall("[a-zA-Z]", stag3)) == stag3:
                       if stag1[0] in string.ascii_letters:
                           if ''.join(re.findall("[a-zA-Z0-9_-]|[.]", stag1[1:])) == stag1[1:]:
                               Flag = 1
                           elif len(stag1) == 1:
                               Flag = 1

    if Flag == 1:
        print(result)
