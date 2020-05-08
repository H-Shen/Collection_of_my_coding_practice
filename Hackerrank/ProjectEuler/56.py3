N = int(input())
print(max(sum(map(int, str(pow(a, b)))) for a in range(2, N) for b in range(2, N)))