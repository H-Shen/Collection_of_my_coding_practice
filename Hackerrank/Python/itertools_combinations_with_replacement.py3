from itertools import combinations_with_replacement

string, num = input().split()
num = int(num)
k = list(combinations_with_replacement(string, num))
k = [list(x) for x in k]
for i in range(len(k)):
    k[i].sort()
k.sort()
for j in range(len(k)):
    print(''.join(k[j]))
