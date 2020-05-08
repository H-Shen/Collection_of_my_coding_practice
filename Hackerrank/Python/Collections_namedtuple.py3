N = int(input())
num = input().split().index('MARKS')
result = 0

for i in range(N):
    result += int(input().split()[num])
Res = result / N
print('%.2f' % Res)
