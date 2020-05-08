from itertools import permutations

string = list(input().strip().split())
k = int(string[1])
S = list(string[0])
result = list(permutations(S, k))
result.sort()

for i in range(len(result)):
    print(''.join(result[i]))
