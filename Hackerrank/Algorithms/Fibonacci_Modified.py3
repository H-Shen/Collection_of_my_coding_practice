def fib(t1, t2, n):
    if n == 1:
        return t1
    elif n == 2:
        return t2

    k = [t1, t2]
    for i in range(3, n + 1):
        k.append(pow(k[-1], 2) + k[-2])
    return k[-1]

t1, t2, n = list(map(int, input().split()))
print(fib(t1, t2, n))
