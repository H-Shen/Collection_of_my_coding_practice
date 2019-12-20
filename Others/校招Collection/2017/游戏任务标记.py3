# https://www.nowcoder.com/practice/2f45f0ef94724e06a4173c91ef60781c

id0, id1 = list(map(int, input().split()))

if (id0 < 1 or id0 > 1024) or (id1 < 1 or id1 > 1024):
    print(-1)
elif id0 == id1:
    print(1)
else:
    print(0)