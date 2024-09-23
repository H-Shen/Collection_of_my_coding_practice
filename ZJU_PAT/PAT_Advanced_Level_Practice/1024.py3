def isPalindrome(s):
    return s == s[::-1]

N, K = list(map(int, input().split()))
haveAns = False

for i in range(K):
    if isPalindrome(str(N)):
        haveAns = True
        break
    N = N + int(str(N)[::-1])
    
if haveAns:
    print(N)
    print(i)
else:
    print(N)
    print(K)