import re

for i in range(int(input())):

    s = input()

    k = re.findall(r'^\((\+|-)?[1-9]+\d*(\.\d+)?, (\+|-)?[1-9]+\d*(\.\d+)?\)$' , s)
    if len(k) == 1:
        a, b = map(float, s[1:-1].split(','))
        if -90 <= a <= 90 and -180 <= b <= 180:
            print('Valid')
            continue

    print('Invalid')
