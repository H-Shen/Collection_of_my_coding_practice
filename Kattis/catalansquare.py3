# https://open.kattis.com/problems/catalansquare
C = [0 for i in range(5001)]
C[0] = 1

for i in range(1, 5001):
    C[i] = 2 * (2 * i - 1) * C[i - 1] // (i + 1)

n = int(input())
s = 0
for i in range(0, n + 1):
    s += C[i] * C[n - i]
print(s)
