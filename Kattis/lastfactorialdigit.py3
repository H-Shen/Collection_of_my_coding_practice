# https://open.kattis.com/problems/lastfactorialdigit

from math import factorial as f
n = int(input())
for i in range(n):
    print(f(int(input())) % 10)
