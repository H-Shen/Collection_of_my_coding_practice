# https://www.nowcoder.com/practice/61cfbb2e62104bc8aa3da5d44d38a6ef
n = int(input())
cnt = 1000

x_max, y_max = n // 6, n // 8
x_max += 1
y_max += 1

for x in range(x_max + 1):
    for y in range(y_max + 1):
        if 6 * x + 8 * y == n and x + y < cnt:
            cnt = x + y

if cnt == 1000:
    print(-1)
else:
    print(cnt)
