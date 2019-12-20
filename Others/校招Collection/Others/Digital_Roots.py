# https://www.nowcoder.com/practice/cef727d0af33479c9fb4a9c120702414

def NumberRoot(s):
    while len(s) > 1:
        s = sum(map(int, s))
        s = str(s)
    return s

try:
    while 1:
        print NumberRoot(raw_input())
except:
    pass