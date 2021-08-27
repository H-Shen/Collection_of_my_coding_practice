class Solution:
    def bestRotation(self, nums: List[int]) -> int:
        n = len(nums)
        diff = [0 for i in range(n)]
        ans = 0
        for i in range(n):
            diff[(1+n+i-nums[i]) % n] -= 1
        for i in range(1,n):
            diff[i] = diff[i] + diff[i-1] + 1
            if diff[i] > diff[ans]:
                ans = i
        return ans