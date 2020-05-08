from itertools import combinations

string = list(input().strip().split())
k = int(string[1])
S = string[0]
result2 = list()

for i in range(1,k + 1):
    result = list(combinations(S, i))
    result = list(map(list,result))
    result = [sorted(result[x]) for x in range(len(result))]
    result.sort()
    result2.extend(result)

for i in range(len(result2)):
    print(''.join(result2[i]))
