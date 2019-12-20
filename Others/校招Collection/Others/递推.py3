# https://ac.nowcoder.com/acm/problem/14607

p = 1000000009

def f(n):
    return ((((3 * pow(2, n + 1, p)) % p - (4 * n) % p + p) % p - pow(n, 2, p) + p ) % p - 6 + p ) % p

try:
    while True:
        print(f(int(input())))
except:
    pass