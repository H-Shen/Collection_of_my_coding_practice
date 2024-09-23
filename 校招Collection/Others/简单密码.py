# https://www.nowcoder.com/practice/7960b5038a2142a18e27e4c733855dac

a = 'abcdefghijklmnopqrstuvwxyza'
b = {'e': 3, 'y': 9, 'n': 6, 'b': 2, 'f': 3, 'r': 7, 'c': 2, 'p': 7, 'z': 9, 'l': 5, 'i': 4, 't': 8, 'h': 4, 'v': 8, 'k': 5, 'q': 7, 'o': 6, 'j': 5, 'x': 9, 'd': 3, 'g': 4, 's': 7, 'w': 9, 'm': 6, 'u': 8, 'a': 2}

try:
    while 1:
        s = raw_input()
        r = ''
        for i in s:
            if i.isupper():
                r += a[a.index(i.lower()) + 1]
            elif i in b:
                r += str(b[i])
            else:
                r += i
        print r
except:
    pass