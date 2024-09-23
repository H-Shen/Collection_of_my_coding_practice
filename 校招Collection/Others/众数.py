# https://www.nowcoder.com/practice/1549bbe3d8f546f888f4290250d9e2a6

from collections import Counter

try:
    while 1:
        print max(Counter(map(int, raw_input().split())).items(), key=lambda x: (x[1], -x[0]))[0]
except:
    pass
