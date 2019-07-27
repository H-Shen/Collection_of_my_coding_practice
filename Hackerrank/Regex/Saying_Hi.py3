import re

for i in range(int(input())):
    s = input()
    k = re.findall(r'^(H|h)(i|I)\s[^Dd]', s)
    if len(k) == 1:
        print(s)
