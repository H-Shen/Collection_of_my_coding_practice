# Enter your code here. Read input from STDIN. Print output to STDOUT

n = int(input())
M = pow(10, 12)
s, currentSum = 0, 0
for i in range(n):
    a, b, c, d = list(map(int, input().split()))
    currentSum = ((a%M * pow(b, c, M)) % M + d%M) % M
    s += currentSum
s %= M
s = str(s)
if len(s) < 12:
    s = '0' * (12 - len(s)) + s
print(s)
