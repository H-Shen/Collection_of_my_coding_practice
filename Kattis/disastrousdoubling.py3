# https://open.kattis.com/contests/amnw6g/problems/disastrousdoubling

n = int(input())
a = 1
A = list(map(int, input().split()))
haveAns = True
for i in A:
    a = 2 * a - i
    if (a < 0):
        haveAns = False
        print("error")
        break

if haveAns:
    print(a % 1000000007)
