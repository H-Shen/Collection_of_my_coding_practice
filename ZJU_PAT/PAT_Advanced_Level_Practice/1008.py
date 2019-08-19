total = 0
arr = map(int, raw_input().split())[1:]
L = len(arr)
current = 0
for i in xrange(L):
    if arr[i] > current:
        total = total + (arr[i] - current) * 6 + 5
    elif arr[i] < current:
        total = total + (current - arr[i]) * 4 + 5
    else:
        total += 5
    current = arr[i]
print total