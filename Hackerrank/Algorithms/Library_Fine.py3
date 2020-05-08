import datetime
D = datetime.datetime

a = list(map(int, input().split()))
b = list(map(int, input().split()))

interval = (D(a[2], a[1], a[0]) - D(b[2], b[1], b[0])).days
if interval <= 0:
    print(0)
elif a[1] == b[1] and a[2] == b[2] :
    print(interval * 15)
elif a[2] == b[2]:
    print((a[1] - b[1]) * 500)
else:
    print(10000)
