S = input()
k = input()
result = list()

if not k in S:
    print((-1, -1))
else:
    len0 = len(S)
    len1 = len(k)

    for i in range(len0):
        if S[i:i + len1] == k:
            result.append((i,i + len1 - 1))

    for j in result:
        print(j)
