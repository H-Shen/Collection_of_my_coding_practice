import re

for i in range(int(input())):
    s = input()
    if re.findall('\d+',s) == []:
        print('NO')
    elif re.findall('\d+',s)[0] == s and len(s) == 10 and s[0] in ['7','8','9']:
        print('YES')
    else:
        print('NO')
