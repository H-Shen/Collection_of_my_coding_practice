from collections import OrderedDict

N = int(input())
result = OrderedDict()

for i in range(N):
    s = input()
    if s in result:
        result[s] += 1
    else:
        result[s] = 1

print(len(result))
print(' '.join(list(map(str,result.values()))))
