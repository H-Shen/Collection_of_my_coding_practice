# https://www.nowcoder.com/practice/ae7e58fe24b14d1386e13e7d70eaf04d

import datetime
D = datetime.datetime
try:
    while 1:
        a = map(int, raw_input().split())
        print (D(a[0], a[1], a[2]) - D(a[0] - 1, 12, 31)).days
except:
    pass