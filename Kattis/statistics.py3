# https://open.kattis.com/problems/statistics
n = 0
try:
    while 1:
        n += 1
        a = list(map(int, input().split()))
        del a[0]
        maxVal, minVal = max(a), min(a)
        print("Case " + str(n) + ": " + str(minVal) + " " + str(maxVal) + " "
              + str(maxVal - minVal))
except:
    pass
