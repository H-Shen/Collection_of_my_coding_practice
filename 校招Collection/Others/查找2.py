# https://www.nowcoder.com/practice/d93db01c2ee44e8a9237d63842aca8aa

try:
    while 1:
        n = input()
        a = dict(zip(raw_input().split(), [0] * n))
        m = input()
        result = map(lambda x:'YES' if x in a else 'NO', raw_input().split())
        for i in result:
            print i
except:
    pass