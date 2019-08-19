def fib():
    yield 1
    yield 1
    a, b = 1, 1
    while 1:
        a, b = b % 10000, (a % 10000 + b % 10000) % 10000
        yield b

table = {}
gen = fib()
for i in xrange(10001):
    current = next(gen)
    table[i] = current

try:
    while 1:
        n = input()
        arr = map(int, raw_input().split())
        print ''.join(map(lambda x:str(table[x]).zfill(4), arr))
except:
    pass
