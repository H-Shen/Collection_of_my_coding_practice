from itertools import combinations

n = int(input())
arr = input().split()
k = int(input())
count = 0
possible = 0
a = combinations(arr, k)

try:
    while 1:
        current = next(a)
        if 'a' in current:
            possible += 1
        count += 1
except:
    pass

result = possible / count
print('%.4f' % result)
