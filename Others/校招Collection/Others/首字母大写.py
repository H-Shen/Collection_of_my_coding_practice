# https://www.nowcoder.com/practice/91f9c70e7b6f4c0ab23744055632467a

try:
    while 1:
        s, result = [raw_input(), '']
        L = len(s)
        result += s[0].upper() if s[0].isalpha() else s[0]
        for i in xrange(1, L):
            result += s[i].upper() if s[i].isalpha() and s[i - 1] in {' ', '\t', '\n'} else s[i]
        print result
except:
    pass