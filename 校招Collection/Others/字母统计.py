# https://www.nowcoder.com/practice/de7bf0945c1c4bd1aa9d49573b831f3c

from collections import Counter
from string import ascii_uppercase as a

try:
    while 1:
        L = Counter(filter(lambda x:x.isupper() is True, raw_input()))
        for i in a:
            print i + ':' + str(L[i]) if i in a else i + ':' + '0'
except:
    pass