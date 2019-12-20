# https://www.nowcoder.com/practice/02d8d42b197646a5bbd0a98785bb3a34
x, y, z, w = list(map(int, input().split()))

A = (x + z) // 2
B = (y + w) // 2
C = (w - y) // 2

if (A - B == x and B - C == y and A + B == z and B + C == w):
    print(A, B, C)
else:
    print('No')
