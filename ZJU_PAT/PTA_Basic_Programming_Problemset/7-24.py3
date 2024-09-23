from math import gcd
m, n = list(map(int, input().split('/')))
temp = gcd(m, n)
m //= temp
n //= temp
print(str(m) + "/" + str(n))