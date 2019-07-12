# https://www.nowcoder.com/practice/dc943274e8254a9eb074298fb2084703

k = set()
for i in range(100, 1000):
    if i == sum(list(map(lambda x : pow(int(x), 3), str(i)))):
        k.add(i)

try:
    while 1:
        haveAns = False
        ansList = []
        a, b = list(map(int, input().split()))
        for j in range(a, b + 1):
            if j in k:
                haveAns = True
                ansList.append(str(j))
        if haveAns:
            print(' '.join(ansList))
        else:
            print('no')
except:
    pass