[N, X] = list(map(int,input().strip().split()))
result = list()
for i in range(X):
    result.append(list(map(float,input().strip().split())))

result0 = list(zip(*result))

for j in range(len(result0)):
    print(round(sum(result0[j]) / len(result0[j]),1))
