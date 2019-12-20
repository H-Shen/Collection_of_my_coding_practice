# https://ac.nowcoder.com/acm/problem/15072

a, b = 1, 2
A = {1 : 1, 2 : 2}

while (len(A) <= 100000):
    a, b = b, a + b
    A[b] = len(A) + 1

try:
    while True:
        print(A[int(input())])
except:
    pass