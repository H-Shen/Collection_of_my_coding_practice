from fractions import gcd
from functools import reduce

def mulGcd(L):
    return reduce(lambda x, y: gcd(x, y), L)
def lcm(x, y):
    return x * y // gcd(x, y)
def mulLcm(L):
   s = len(L)
   if s == 0:
       return 0
   if s == 1:
       return L[0]
   else:
       a = lcm(L[0], L[1])
       for i in range(2, s):
           a = lcm(a, L[i])
       return a

n,m = input().strip().split(' ')
n,m = [int(n),int(m)]
a = [int(a_temp) for a_temp in input().strip().split(' ')]
b = [int(b_temp) for b_temp in input().strip().split(' ')]

minVal, maxVal = mulLcm(a), mulGcd(b)
count = 0
for i in range(minVal, maxVal + 1):
    if i % minVal == 0 and maxVal % i == 0:
        count += 1
print(count)
