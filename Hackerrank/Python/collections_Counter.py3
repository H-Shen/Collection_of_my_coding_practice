N = int(input())
List = list(map(int,input().split()))
T = int(input())
S = 0

for i in range(T):
    a = list(map(int,input().split()))
    if a[0] in List:
        S += a[1]
        List.remove(a[0])

print(S)
