import re

table = 'QWRTYPSDFGHJKLZXCVBNMqwrtypsdfghjklzxcvbnm'
s = input()
a = re.finditer('[aeiouAEIOU]+',s)
result = list()

for i in a:
    content = i.group()
    span = i.span()
    if span[0] == 0:
        continue
    if span[1] == len(s):
        continue
    elif s[span[0] - 1] in table and s[span[1]] in table:
        if len(content) >= 2:
            result.append(content)
if result == []:
    print(-1)
else:
    for x in result:
        print(x)
