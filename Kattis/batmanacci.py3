# https://open.kattis.com/problems/batmanacci

n, k = list(map(int, input().split()))

A = [0, 1]

for i in range(n + 3):
    A.append(A[-1] + A[-2])

while n > 2:
    if (k <= A[n - 2]):
        n -= 2
    else:
        k -= A[n - 2]
        n -= 1

if n == 1:
    print("N")
else:
    print("A")
