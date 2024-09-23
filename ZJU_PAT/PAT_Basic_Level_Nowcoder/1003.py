def fib():
    yield 1
    yield 2
    a, b = 1, 2
    while 1:
        a, b = b, a + b
        yield b
gen = fib()
result = [next(gen) for i in xrange(90)]

try:
    while 1:
        print result[input() - 1]
except:
    pass