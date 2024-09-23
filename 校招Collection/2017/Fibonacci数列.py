# https://www.nowcoder.com/practice/18ecd0ecf5ef4fe9ba3f17f8d00d2d66

a = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269]
Len = len(a)

N = input()
step = 0

for i in xrange(Len - 1):
    if a[i] == N or a[i + 1] == N:
        break
    elif a[i] < N < a[i + 1]:
        step = min([N - a[i], a[i + 1] - N])
        break

print step