# https://www.nowcoder.com/practice/e4af1fe682b54459b2a211df91a91cf3

t = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
try:
    while 1:
        Key, a = raw_input(), raw_input()
        KeyUpper = Key.upper()
        unique = set(KeyUpper)
        m, n = sorted(unique, key=KeyUpper.index) + [i for i in t if not i in unique], t
        table = dict(zip(n, m))
        r = ''
        for i in a:
            if i.islower():
                r += table[i.upper()].lower()
            elif i.isupper():
                r += table[i]
            else:
                r += i
        print r
except:
    pass