# https://ac.nowcoder.com/acm/problem/15194

try:
    while 1:
        T = int(input())
        for i in range(T):
            p, q = list(map(int, input().split()))
            if (p % q == 0):
                print(p // q - 1)
            else:
                print(p // q)
except:
    pass