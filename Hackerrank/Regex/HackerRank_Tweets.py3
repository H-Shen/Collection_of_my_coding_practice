import re

n = int(input())
count = 0

for i in range(n):
    s = input()
    count += len(re.findall(r'hackerrank', s, re.I))
print(count)
