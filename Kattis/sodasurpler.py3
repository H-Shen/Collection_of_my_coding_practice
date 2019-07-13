# https://open.kattis.com/problems/sodasurpler

e, c, f = list(map(int, input().split()))

cnt = 0
e = e + c

while True:

    a = e // f
    b = e % f

    cnt += a
    if a == 0:
        break
    e = a + b

print(cnt)
