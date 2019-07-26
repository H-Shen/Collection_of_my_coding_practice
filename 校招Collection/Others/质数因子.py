# https://www.nowcoder.com/practice/196534628ca6490ebce2e336b47b3607

def isPrime(n):
    return not [i for i in xrange(2, int(n ** 0.5) + 1) if n % i == 0]

def primeFactors(x):
    a = [i for i in xrange(2, int(x ** 0.5) + 1) if isPrime(i) and x % i == 0]
    if len(a) == 0:
        return str(x) + ' '
    else:
        factors = []
        for i in a:
            while x % i == 0:
                factors.append(i)
                x //= i
        if x != 1:
            factors.append(x)
        return ' '.join(map(str, factors)) + ' '

print primeFactors(input())