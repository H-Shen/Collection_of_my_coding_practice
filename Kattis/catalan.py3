# https://open.kattis.com/problems/catalan
C = [1, 1]
n = 1

while len(C) <= 5005:
    C.append(2 * (2 * n + 1) * C[-1] // (n + 2))
    n += 1

q = int(input())
for i in range(q):
    print(C[int(input())])
