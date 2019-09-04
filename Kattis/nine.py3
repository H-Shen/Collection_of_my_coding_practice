# -*- coding: utf-8 -*-
# https://open.kattis.com/problems/nine

MOD = 1000000007
T = int(input())
for i in range(T):
    print((pow(9, int(input()) - 1, MOD) * (8 % MOD)) % MOD)
