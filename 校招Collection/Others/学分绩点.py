# https://www.nowcoder.com/practice/a0c09a7e0da04e728810a8aca7226b7b

from __future__ import division

def transform(point):
    if 90 <= point <= 100:
        return 4
    elif 85 <= point <= 89:
        return 3.7
    elif 82 <= point <= 84:
        return 3.3
    elif 78 <= point <= 81:
        return 3
    elif 75 <= point <= 77:
        return 2.7
    elif 72 <= point <= 74:
        return 2.3
    elif 68 <= point <= 71:
        return 2
    elif 64 <= point <= 67:
        return 1.5
    elif 60 <= point <= 63:
        return 1
    else:
        return 0

def gpa(n, score, point):
    pointList = map(int, point)
    scoreList = map(int, score)
    result = sum(map(lambda x:x[0] * x[1], zip(map(transform, pointList), scoreList))) / sum(scoreList)
    return "%.2f" % result

try:
    while 1:
        print gpa(input(), raw_input().split(), raw_input().split())
except:
    pass