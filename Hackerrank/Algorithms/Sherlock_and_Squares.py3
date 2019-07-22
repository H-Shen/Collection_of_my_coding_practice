MAXN = 31622
k = [pow(i, 2) for i in range(1, MAXN + 1)]

n = int(input())

for j in range(n):

    left, right = map(int, input().split())
    firstTime = True

    if left > 999950884:
        print(0)
    elif left <= 999950884 and right > 999950884:
        for i in range(MAXN):
            if k[i] >= left:
                leftPos = i
                break
        print(MAXN - i)

    else:
        for i in range(MAXN):
            if k[i] > right:
                rightPos = i
                break
            if firstTime == True and k[i] >= left:
                leftPos = i
                firstTime = False

        if firstTime:
            print(0)
        else:
            print(rightPos - leftPos)
