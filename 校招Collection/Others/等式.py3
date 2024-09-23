# https://ac.nowcoder.com/acm/problem/15325

import random
from functools import reduce
from collections import Counter

def gcd(a, b):
    return gcd(b, a % b) if b > 0 else a

def mod_mul(a, b, n):
    result = 0
    while b > 0:
        if (b & 1) > 0:
            result = (result + a) % n
        a = (a + a) % n
        b = (b >> 1)
    return result

def MillerRabinPrimeCheck(n):
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
    s = 5
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

def Pollard_rho(x, c):
    (i, k) = (1, 2)
    x0 = random.randint(0, x)
    y = x0
    while 1:
        i += 1
        x0 = (mod_mul(x0, x0, x) + c) % x
        d = gcd(y - x0, x)
        if d != 1 and d != x:
            return d
        if y == x0:
            return x
        if i == k:
            y = x0
            k += k

def PrimeFactorsListGenerator(n):
    result = []
    if n <= 1:
        return None
    if MillerRabinPrimeCheck(n):
        return [n]
    p = n
    while p >= n:
        p = Pollard_rho(p, random.randint(1, n - 1))
    result.extend(PrimeFactorsListGenerator(p))
    result.extend(PrimeFactorsListGenerator(n // p))
    return result

def PrimeFactorsListCleaner(n):
    return Counter(PrimeFactorsListGenerator(n))

def DivisorsCount(n):
    if n <= 1:
        return n
    return reduce(lambda x,y:x * y,[v + 1 for k, v in PrimeFactorsListCleaner(n).items() if k > 1])

T = int(input())
for i in range(T):
    n = int(input())
    ans = DivisorsCount(pow(n, 2))
    if ans % 2 == 0:
        ans //= 2
    else:
        ans = (ans - 1) // 2 + 1
    print(ans)