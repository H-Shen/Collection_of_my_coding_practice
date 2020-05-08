for _ in range(int(input())):
    a = list(map(int, input().split()))
    if max(a) == min(a):
        print(1)
    else:
        n = min(a)
        result = []
        s = a[0] * a[1]
        for i in range(1, n + 1):
            if s % (i ** 2) == 0:
                result.append(i)
        result.reverse()

        result2 = 0
        for j in result:
            if a[0] % j == 0 and a[1] % j == 0 and j > result2:
                result2 = j

        answer = s // (result2 ** 2)
        print(answer)
