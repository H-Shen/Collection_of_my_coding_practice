# -*- coding: utf-8 -*-
# https://open.kattis.com/problems/sjecista

def f(n):
    return n * (n - 1) * (n - 2) * (n - 3) // 24

print(f(int(input())))
