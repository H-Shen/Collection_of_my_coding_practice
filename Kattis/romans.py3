# https://open.kattis.com/problems/romans

x = float(input()) * 1000 * 5280 / 4854
if x - int(x) >= 0.5:
    print(int(x) + 1)
else:
    print(int(x))
