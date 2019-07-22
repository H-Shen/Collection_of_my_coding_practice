#!/bin/python3

import sys
from itertools import combinations

s_len = int(input().strip())
s = input().strip()

item = set(s)
k = combinations(item, 2)
result = list()
length = list()

try:
    while 1:
        p = set(next(k))
        m = list(item ^ p)
        t = s
        for i in range(len(m)):
            t = t.replace(m[i],'')
        result.append(t)
except:
    pass

for j in range(len(result)):
    str1 = list(set(result[j]))[0] * 2
    str2 = list(set(result[j]))[1] * 2
    if not str1 in result[j]:
        if not str2 in result[j]:
            length.append(len(result[j]))

if length == []:
    print(0)
else:
    print(max(length))
