a = int(input())
A = set(map(int,input().strip().split()))
N = int(input())

for i in range(N):
    I = input().split()
    b = int(I[1])
    B = set(map(int,input().strip().split()))

    if I[0] == 'intersection_update':
        A &= B
    elif I[0] == 'update':
        A |= B
    elif I[0] == 'symmetric_difference_update':
        A ^= B
    elif I[0] == 'difference_update':
        A -= B

print(sum(A))
