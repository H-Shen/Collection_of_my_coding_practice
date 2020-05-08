#!/bin/python3

import sys

s = input().strip()
n = int(input().strip())

A = s.count('a')
L = len(s)
n1 = n // L
n2 = n % L

result = n1 * A
result += s[:n2].count('a')

print(result)
