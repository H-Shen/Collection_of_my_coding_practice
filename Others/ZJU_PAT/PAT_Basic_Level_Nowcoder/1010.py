def fib():
    yield 1
    yield 2
    a, b = 1, 2
    while 1:
        a, b = b, a + b
        yield b

try:
    while 1:
        n = input()
        gen = fib()
        for i in xrange(n):
            current = next(gen)
        print current
except:
    pass