# https://www.nowcoder.com/practice/05182d328eb848dda7fdd5e029a56da9

from collections import Counter

try:
    while 1:
        s = raw_input()
        Min = min(Counter(s).values())
        a = filter(lambda x:x[1] == Min, Counter(s).items())
        for i, j in a:
            s = s.replace(i, '')
        print s
except:
    pass