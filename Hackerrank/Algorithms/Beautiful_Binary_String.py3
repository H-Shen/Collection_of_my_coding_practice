#!/bin/python3

import sys

n = int(input().strip())
B = input().strip()
B_New = B.replace('010','')

result = (len(B) - len(B_New)) // 3

print(result)
