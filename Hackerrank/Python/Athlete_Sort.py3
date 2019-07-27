n, i = list(map(int,input().split()))
result = list()

for x in range(n):
    result.append(list(map(int,input().split())))

k = int(input())
Res = sorted(result,key=lambda w: w[k])

for e in Res:
    print(' '.join(map(str,e)))
