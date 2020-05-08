import re
mailList = list()

n = int(input())
for i in range(n):
    s = input()
    mailList += re.findall(r'[\w]*[\.]*\w+@\w+\.\w+[\.\w]*\w+', s)
mailList = sorted(set(mailList))
print(';'.join(mailList))
