# https://ac.nowcoder.com/acm/problem/14514

MAX = 105
MOD = 9
a = [1, 1]
while (len(a) < MAX):
    a.append( (6 * a[-1] + 8 * a[-2]) % MOD )

try:
    while True:
        print(a[int(input()) - 1])
except:
    pass