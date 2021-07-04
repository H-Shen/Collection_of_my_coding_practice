MOD = 10**9+7

class Solution:
    def countGoodNumbers(self, n: int) -> int:
        if n % 2 == 0:
            return pow(4,n//2,MOD) * pow(5,n//2,MOD) % MOD
        return pow(4,(n-1)//2,MOD) * pow(5,(n+1)//2,MOD) % MOD