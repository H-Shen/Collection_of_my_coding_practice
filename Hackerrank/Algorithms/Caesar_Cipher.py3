#!/bin/python3

import sys
import string


n = int(input().strip())
s = input().strip()
k = int(input().strip())
result = []

for i in range(len(s)):

    if s[i] in string.ascii_letters:
        a = ord(s[i])
        if 65 <= a <= 90:
            b = a + k
            while not 65 <= b <= 90:
                b -= 26
            result.append(chr(b))
        elif 97 <= a <= 122:
            b = a + k
            while not 97 <= b <= 122:
                b -= 26
            result.append(chr(b))

    else:
        result.append(s[i])

print(''.join(result))
