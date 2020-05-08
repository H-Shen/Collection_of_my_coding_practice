import re

def email(result):

    if result.count('@') == 1 and result.count('.') == 1:

        para1 = result.index('@')
        para2 = result.index('.')

        stag1 = result[:para1]
        stag2 = result[(para1 + 1):para2]
        stag3 = result[(para2 + 1):]

        if 1 <= len(stag3) <= 3 and len(stag1) >= 1 and len(stag2) >= 1:
            if ''.join(re.findall("[a-zA-Z0-9]", stag2)) == stag2:
                if ''.join(re.findall("[a-zA-Z0-9_-]", stag1)) == stag1:
                    return result

    return 1

t = int(input())
ans = []
for i in range(t):
    result = input()
    if email(result) != 1:
        ans.append(result)
ans.sort()
print(ans)