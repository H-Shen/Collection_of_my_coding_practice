import re

def Filter(s):
    if len(s) != 10:
        return False
    s1 = re.findall('[a-zA-Z0-9]+',s)
    if s1 == []:
        return False
    if s1[0] != s:
        return False
    if len(set(s)) != len(s):
        return False
    s2 = ''.join(re.findall('\d+',s))
    if len(s2) < 3:
        return False
    s3 = ''.join(re.findall('[A-Z]',s))
    if len(s3) < 2:
        return False
    return True

result = list()
for i in range(int(input())):
    k = input()
    if k in result:
        continue
    if Filter(k) == True:
        result.append(k)
        print('Valid')
    else:
        print('Invalid')
