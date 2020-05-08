a = int(input())
b = input()
c = b.split()

for i in range(0,a):
    c[i] = int(c[i])

print(hash(tuple(c)))
