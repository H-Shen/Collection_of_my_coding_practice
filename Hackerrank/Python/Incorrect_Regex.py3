import re

t = int(input())
a = 'a123b'
for a0 in range(t):
    S = input()
    try:
        re.findall(r"{string}".format(string = S), a)
    except:
        print(False)
    else:
        print(True)
