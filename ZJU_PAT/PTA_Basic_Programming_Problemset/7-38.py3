a, n = list(map(int, input().split()))
print(a * (10 * (pow(10, n) - 1) // 81 - n // 9))