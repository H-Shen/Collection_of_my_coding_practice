# https://www.nowcoder.com/practice/aed1c7bbc2604e7c9661a2348b0541b8

try:
    while 1:
        s = raw_input().split('_')
        print s[0] + ''.join(map(lambda x:x.capitalize(), s[1:]))
except:
    pass