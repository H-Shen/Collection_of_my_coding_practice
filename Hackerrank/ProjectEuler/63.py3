N = int(input())
i = 1
b = []
while len(str(i ** N)) <= N:
    if len(str(i ** N)) == N:
        b.append(i ** N)
    i += 1
for j in b:
    print(j)
