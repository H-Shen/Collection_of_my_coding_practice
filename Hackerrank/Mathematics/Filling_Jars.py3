N, M = map(int, input().split())
result = 0
for i in range(M):
    a, b, k = map(int, input().split())
    result += k * (b - a + 1)
print(int(result / N))
