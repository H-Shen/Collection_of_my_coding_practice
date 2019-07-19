import fractions

for i in range(int(input())):
    A, M = list(map(int,input().split()))
    if A ** 0.5 % 1 == 0:
        print('YES')
    elif (M > 2 and fractions.gcd(A, M) == 1 and pow(A, (M - 1) // 2, M)== 1):
        print('YES')
    elif M == 2:
        print('YES')
    else:
        print('NO')
