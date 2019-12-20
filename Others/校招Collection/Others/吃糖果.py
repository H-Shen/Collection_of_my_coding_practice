# https://www.nowcoder.com/practice/72015680c32b449899e81f1470836097

def fib():
    yield 1
    yield 2
    a, b = 1, 2
    while 1:
        a, b = b, a + b
        yield b

try:
    while 1:
        gen = fib()
        for i in xrange(input()):
            s = next(gen)
        print s
except:
    pass