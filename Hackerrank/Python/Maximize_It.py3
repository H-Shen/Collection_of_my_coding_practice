# Enter your code here. Read input from STDIN. Print output to STDOUT

from itertools import product

K, M = list(map(int,input().split()))

result = list()

for i in range(K):

    arr = input().split()
    n = int(arr[0])
    arr = list(map(int, arr[1:]))
    arrNew = [(j % M) ** 2 for j in arr]
    result.append(arrNew)

a = [sum(x) % M for x in product(*result)]
print(max(a))
