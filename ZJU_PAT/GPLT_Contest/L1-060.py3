x, y = list(map(int, input().split()))
a = 10000 - x * y - 2 * y * (100 - x) - (100 - y) * (100 - x)
if (a % 2 == 0):
    print(a // 2)
else:
    print(a / 2)