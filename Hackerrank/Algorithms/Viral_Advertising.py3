from math import floor as e

n = int(input())
LikeList = list()

def a(m):
    while 1:
        Like = e(m / 2)
        NextDayTotal = e(m / 2) * 3
        yield LikeList.append(Like)
        m = NextDayTotal

q = a(5)

for i in range(n):
    q.__next__()

print(sum(LikeList))
