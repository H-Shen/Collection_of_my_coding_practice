import re

for i in range(int(input())):
    s = input().strip()
    a = re.findall(r'^\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}$', s)

    if len(a) == 1 and a[0] == s:
        k = list(map(lambda x: 0 <= int(x) <= 255 and str(x) == str(int(x)), s.split('.')))
        if k == [True, True, True, True]:
            print('IPv4')
            continue

    b = re.findall(r'^[0-9a-f]{1,4}\:[0-9a-f]{1,4}\:[0-9a-f]{1,4}\:[0-9a-f]{1,4}\:[0-9a-f]{1,4}\:[0-9a-f]{1,4}\:[0-9a-f]{1,4}\:[0-9a-f]{1,4}$', s)

    if len(b) == 1 and b[0] == s:
        print('IPv6')
    else:
        print('Neither')
