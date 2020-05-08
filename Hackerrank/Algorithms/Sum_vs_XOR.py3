#!/bin/python3

import sys

n = int(input().strip())
print(2 ** (bin(n)[2:].count('0')) if n else 1)
