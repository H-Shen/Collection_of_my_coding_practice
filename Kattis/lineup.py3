# https://open.kattis.com/submissions/3174398

n = int(input())
A = list()
for i in range(n):
    A.append(input())
B = A[::]
C = A[::]

B.sort()
C.sort(reverse=True)

if A == B:
    print("INCREASING")
elif A == C:
    print("DECREASING")
else:
    print("NEITHER")
