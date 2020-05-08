n = int(input())
s = ''

for i in range(n):
    s = s + ' ' + input()
t = int(input())
for j in range(t):
    w = input()
    w2 = w[:-2] + 'se'
    num = s.count(w) + s.count(w2)
    print(num)
