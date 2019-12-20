# https://www.nowcoder.com/practice/a927f3eb359843ddaafb9b29d4899e58

def isPrime(n):
    return not [i for i in xrange(2, int(n ** 0.5) + 1) if n % i == 0]

def primeFactors(x):
    a = [i for i in xrange(2, int(x ** 0.5) + 1) if isPrime(i) and x % i == 0]
    if len(a) == 0:
        return 'No'
    else:
        factors = []
        for i in a:
            while x % i == 0:
                if i in factors:
                    return 'Yes'
                factors.append(i)
                x //= i
        if x != 1:
            factors.append(x)
        return 'No'
try:
    while 1:
        n = input()
        if n == 0:
            break
        else:
            print primeFactors(n)
except:
    pass