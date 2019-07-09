n = int(input())
for i in range(n):
    s = input()
    if ("ong," in s and "ong." in s):
        a = s.split()
        if ',' not in a[-1]:
            _ = a.pop()
        if ',' not in a[-1]:
            _ = a.pop()
        if ',' not in a[-1]:
            _ = a.pop()
        a.append("qiao")
        a.append("ben")
        a.append("zhong.")
        print(' '.join(a))
    else:
        print("Skipped")