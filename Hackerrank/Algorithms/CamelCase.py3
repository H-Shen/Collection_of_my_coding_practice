#!/bin/python3

import sys
import re

s = input().strip()
print(len(re.sub('[a-z]','',s)) + 1)
