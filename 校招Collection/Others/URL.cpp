# https://ac.nowcoder.com/acm/problem/14327

import base64

def convert(s):
    s = "AA" + s + "ZZ"
    return "thunder://" + base64.b64encode(s)

try:
    while 1:
        print convert(raw_input())
except:
    pass