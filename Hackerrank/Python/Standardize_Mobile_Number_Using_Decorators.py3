result = list()
for i in range(int(input())):
    s = input()
    if len(s) == 10:
        string = '+91 ' + s[:5] + ' ' + s[-5:]
        result.append(string)
    elif len(s) == 11:
        string = '+91 ' + s[1:6] + ' ' + s[-5:]
        result.append(string)
    elif len(s) == 12:
        string = '+91 ' + s[2:7] + ' ' + s[-5:]
        result.append(string)
    elif len(s) == 13:
        string = '+91 ' + s[3:8] + ' ' + s[-5:]
        result.append(string)
result.sort()
for j in result:
    print(j)