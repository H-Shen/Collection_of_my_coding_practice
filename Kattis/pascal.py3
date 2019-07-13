#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# https://open.kattis.com/problems/pascal

import random

def gcd(a, b):
    """
    a, b: integers
    returns: a positive integer, the greatest common divisor of a & b.
    """
    if a == 0:
        return b
    if a < 0:
        return gcd(-a, b)
    while b > 0:
        c = a % b
        a, b = b, c
    return a


def mod_mul(a, b, n):
    # Calculate a * b % n iterately.
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

def Pollard_rho(x, c):
    '''
    Consider c as a constant integer.
    '''
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
    '''
    Rearrange the result from PrimeFactorsListGenerator into a dict.
    Return a dict that consists of item(factor:count)
    '''
    from collections import Counter
    return Counter(PrimeFactorsListGenerator(n))


def Divisors(n):
    if MillerRabinPrimeCheck(n):
        return [1, n]
    if n == 1:
        return [1]
    if n == 0:
        return []
    def DivisorsHelperFunc(n):
        FactorDict = dict(PrimeFactorsListCleaner(n))
        PrimeSort = sorted(FactorDict.keys())
        def gen(n=0):
            if n == len(PrimeSort):
                yield 1
            else:
                pows = [1]
                for j in range(FactorDict[PrimeSort[n]]):
                    pows.append(pows[-1] * PrimeSort[n])
                for q in gen(n + 1):
                    for p in pows:
                        yield p * q
        for p in gen():
            yield p
    return DivisorsHelperFunc(n)


n = int(input())
if n == 1:
    print(0)
else:
    A = list(Divisors(n))
    A.remove(max(A))
    print(n - max(A))
