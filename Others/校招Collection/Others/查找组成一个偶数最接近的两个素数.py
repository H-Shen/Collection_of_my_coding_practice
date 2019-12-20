# https://www.nowcoder.com/practice/f8538f9ae3f1484fb137789dec6eedb9

def isPrime(x):
    return False if any([bool(x % i == 0) for i in xrange(2, int(x))]) else True

try:
    while 1:
        s = input()
        half = s / 2
        head, tail = half, half
        while 1:
            if not (isPrime(head) and isPrime(tail)):
                head -= 1
                tail += 1
            else:
                print head
                print tail
                break
except:
    pass
