# https://open.kattis.com/problems/ostgotska

from fractions import Fraction as f

a = input().split()
cnt = 0
for i in a:
    if i.count("ae") > 0:
        cnt += 1

if f(cnt, len(a)) >= f(2, 5):
    print("dae ae ju traeligt va")
else:
    print("haer talar vi rikssvenska")
