from math import factorial as f
for i in range(int(input())):
    N, M = list(map(int,input().split()))
    result = (f(N + M - 1) // (f(N) * f(M - 1))) % 1000000007
    print(result)

