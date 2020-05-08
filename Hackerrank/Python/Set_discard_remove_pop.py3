n = int(input())
s = set(map(int, input().split()))
N = int(input())

for i in range(N):
    I = input().split()
    if I[0] == 'pop':
        NoOutput = s.pop()
    elif I[0] == 'remove' or I[0] == 'discard':
        s.discard(int(I[1]))
print(sum(s))
