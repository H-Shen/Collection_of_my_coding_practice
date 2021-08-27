from math import factorial
mod = 10**9+7
n = 1005
dp = [[-1]*n for i in range(n)]

def firstTypeStirling(n,k):
    if (n>0 and k==1):
        return factorial(n-1)
    if (n==k):
        return 1
    if (k==n-1):
        return n*(n-1)//2
    if dp[n][k] != -1:
        return dp[n][k]
    dp[n][k] = (n-1)*firstTypeStirling(n-1, k)+firstTypeStirling(n-1, k-1)
    return dp[n][k]

class Solution:
    def rearrangeSticks(self, n: int, k: int) -> int:
        return firstTypeStirling(n,k) % mod