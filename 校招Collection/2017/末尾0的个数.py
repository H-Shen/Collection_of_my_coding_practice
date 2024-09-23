# https://www.nowcoder.com/practice/6ffdd7e4197c403e88c6a8aa3e7a332a

from math import factorial as f
n = input()
s = str(f(n))[::-1]
count = 0
for i in s:
    if i != '0':
        break
    count += 1
print count