import re

for i in range(int(input())):
    s = input()
    k = re.findall(r'^[a-z]{0,3}[0-9]{2,8}[A-Z]{3,}', s)
    if len(k) == 1 and k[0] == s:
        print('VALID')
    else:
        print('INVALID')
