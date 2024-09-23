# https://ac.nowcoder.com/acm/problem/14571

try:
    while True:
        n = int(input())
        A = ['*' * i for i in range(1, n * 2, 2)]
        for i in A:
            print(i.center(n * 2 - 1).rstrip())
except:
    pass