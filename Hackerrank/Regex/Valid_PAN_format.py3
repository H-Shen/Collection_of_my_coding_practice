import re

for i in range(int(input())):
    s = input()
    a = re.findall(r'^[A-Z]{5}\d{4}[A-Z]$', s)
    print("YES") if len(a) == 1 and a[0] == s else print("NO")
