# https://www.nowcoder.com/practice/22fdeb9610ef426f9505e3ab60164c93

try:
    while 1:
        a, b = raw_input(), raw_input()
        A, B = set(a), set(b)
        print str((A | B == B)).lower()
except:
    pass