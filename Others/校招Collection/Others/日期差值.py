# https://www.nowcoder.com/practice/ccb7383c76fc48d2bbc27a2a6319631c

from datetime import datetime

def Date(n):
    return datetime(int(n[:4]), int(n[4:6]), int(n[-2:]))
try:
    while 1:
        a, b = raw_input(), raw_input()
        Days = (Date(b) - Date(a)).days
        print Days + 1
except:
    pass