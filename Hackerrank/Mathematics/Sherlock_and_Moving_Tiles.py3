l,s1,s2 = list(map(int,input().split()))
for _ in range(int(input())):
    q = int(input())
    t = (l - q ** 0.5) * (2 ** 0.5) / abs(s1 - s2)
    print('%.4f' % t)