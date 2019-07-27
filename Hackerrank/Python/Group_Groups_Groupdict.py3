# Enter your code here. Read input from STDIN. Print output to STDOUT

import string
table = string.ascii_letters + string.digits
s = input()
Flag = 0
if len(s) == 1:
    print(-1)
    Flag = 1
else:
    for i in range(len(s) - 1):
        if s[i] == s[i + 1] and s[i] in table:
            print(s[i])
            Flag = 1
            break

if Flag == 0:
    print(-1)