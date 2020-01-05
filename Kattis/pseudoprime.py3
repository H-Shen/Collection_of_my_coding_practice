# https://open.kattis.com/problems/pseudoprime
import random

def mod_mul(a, b, n):
    # Calculate a * b % n iterately.
    result = 0
    while b > 0:
        if (b & 1) > 0:
            result = (result + a) % n
        a = (a + a) % n
        b = (b >> 1)
    return result

def isPrime(n):
    if n in {2, 3, 5, 7, 11}:
        return True
    elif (n == 1 or n % 2 == 0 or n % 3 == 0 or n % 5 == 0 or n % 7 == 0 or n % 11 == 0):
        return False
    k = 0
    u = n - 1
    while not (u & 1) > 0:
        k += 1
        u = (u >> 1)
    random.seed(0)
    s = 5 #If the result isn't right, then add the var s.
    for i in range(s):
        x = random.randint(2, n - 1)
        if x % n == 0:
            continue
        x = pow(x, u, n)
        pre = x
        for j in range(k):
            x = mod_mul(x, x, n)
            if (x == 1 and pre != 1 and pre != n - 1):
                return False
            pre = x
        if x != 1:
            return False
        return True


while True:
    p, a = list(map(int, input().split()))
    if p == 0 and a == 0:
        break
    if not isPrime(p) and pow(a, p, p) == a:
        print("yes")
    else:
        print("no")
