# https://open.kattis.com/problems/pot
cnt = 0
for i in range(int(input())):
    a = input()
    cnt = cnt + pow(int(a[:-1]), int(a[-1]))
print(cnt)
