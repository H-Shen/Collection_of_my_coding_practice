# https://www.nowcoder.com/practice/7f4be54b37a04fdaa4ee545819151114

def isPrime(n):
    return not [i for i in xrange(2, int(n ** 0.5) + 1) if n % i == 0]

table = [x for x in xrange(2, 10000) if isPrime(x) and str(x)[-1] == '1']

try:
    while 1:
        n = input()
        if n <= 11:
            print -1
        else:
            result = []
            for i in table:
                if i >= n:
                    break
                else:
                    result.append(str(i))
            print ' '.join(result)
except:
    pass
