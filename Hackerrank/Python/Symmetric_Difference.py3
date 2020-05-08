M = int(input())
m = input()
N = int(input())
n = input()

m = set(map(int,m.split()))
n = set(map(int,n.split()))

result = list(m.difference(n) | n.difference(m))
result.sort()

for i in range(len(result)):
    print(result[i])
