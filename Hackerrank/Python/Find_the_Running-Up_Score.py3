N = int(input())
a = input()
a = a.split()
for i in range(N):
    a[i] = int(a[i])
maxVal = max(a)
minVal = min(a)

for j in range(N):
    if a[j] == maxVal:
        a[j] = minVal  # Change all maximums to minimums.
print(max(a))
