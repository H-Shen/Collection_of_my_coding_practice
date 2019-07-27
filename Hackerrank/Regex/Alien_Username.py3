import re

for i in range(int(input())):
    s = input()
    phase1 = re.findall(r'^(_|\.)[0-9]+$', s)
    phase2 = re.findall(r'^(_|\.)[0-9]+\_$', s)
    if len(phase1) == 1 or len(phase2) == 1:
        print('VALID')
    else:
        a = re.findall(r'^(_|\.)[0-9]+(0|[A-Za-z]+)$', s)
        b = re.findall(r'^(_|\.)[0-9]+(0|[A-Za-z]+).*\_$', s)
        if len(a) == 1 or len(b) == 1:
            print('VALID')
        else:
            print('INVALID')
