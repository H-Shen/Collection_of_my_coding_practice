# https://open.kattis.com/problems/minimumscalar
n = int(input())
for i in range(1, n + 1):
    _ = input()
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    A_copy = A[::]
    B_copy = B[::]

    A.sort()
    B.sort(reverse = True)

    A_copy.sort(reverse = True)
    B_copy.sort()

    print("Case #" + str(i) + ": " + str(min(sum([A[i] * B[i] for i in range(len(A))]), sum([A[i] * B[i] for i in range(len(A))]))))
