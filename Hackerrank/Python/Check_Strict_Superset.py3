A = set(input().split())
N = int(input())
Flag = True

for i in range(N):
    B = set(input().split())
    if A & B != B or A == B:
        Flag = False

if Flag == False:
    print('False')
else:
    print('True')
