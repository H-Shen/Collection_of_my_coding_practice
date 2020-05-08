from collections import defaultdict

n, m = list(map(int,input().split()))
A = list()
d = defaultdict(list)

for i in range(n):
    A.append(input())

setA = set(A)
sortList = list()

for j in range(m):
    char = input()
    sortList.append(char)
    for k in range(n):
        if char == A[k]:
            d[char].append(k + 1)
    if not char in setA:
        d[char].append(-1)


for q in sortList:
    tmp = d[q]
    tmp = list(set(tmp))
    tmp.sort()
    tmp = list(map(str,tmp))
    print(' '.join(tmp))
