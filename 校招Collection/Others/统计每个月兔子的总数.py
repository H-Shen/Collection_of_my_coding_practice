# https://www.nowcoder.com/practice/1221ec77125d4370833fd3ad5ba72395

def fib():
    yield 1
    yield 1
    a, b = 1, 1
    while 1:
        a, b = b, a + b
        yield b

s = []
q = fib()

for i in xrange(50):
    s.append(next(q))

try:
    while 1:
        n = input()
        print s[n - 1]
except:
    pass