ans = input().split()
n = int(ans[0])
m = int(ans[1])

ARRAY = input().split()
ARRAY = [int(ARRAY[i]) for i in range(n)]

A = input().split()
A = set([int(A[i]) for i in range(m)])
B = input().split()
B = set([int(B[i]) for i in range(m)])

print(sum([(i in A) - (i in B) for i in ARRAY]))
