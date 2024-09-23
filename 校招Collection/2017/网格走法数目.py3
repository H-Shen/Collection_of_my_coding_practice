# https://www.nowcoder.com/practice/e27b9fc9c0ec4a17a5064fb6f5ab13e4

from math import factorial as f

def countWays(x, y):
    return f(x - 1 + y - 1) // (f(x - 1) * f(y - 1))

a, b = list(map(int, input().split()))
a += 1
b += 1
print(countWays(a, b))