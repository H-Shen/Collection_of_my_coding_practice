# https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded

from datetime import datetime as f

try:
    while 1:
        y, m, d = map(int, raw_input().split())
        print (f(y, m, d) - f(y - 1, 12, 31)).days
except:
    pass