def fib():
    yield 1
    yield 2
    a = [1, 2]
    while 1:
        a.append(a[-1] + a[-2])
        yield a[-1]

try:
    while 1:
        n = int(input())
        gen = fib()
        for i in range(n):
            current = next(gen)
        print(current)
except:
    pass