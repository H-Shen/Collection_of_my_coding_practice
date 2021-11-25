func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func maxSubArray(nums []int) int {
	n := len(nums)
	dp := make([]int, n)
	dp[0] = nums[0]
	for i := 1; i < n; i++ {
		dp[i] = max(nums[i], dp[i-1] + nums[i])
	}
    ans := -0x3f3f3f3f
	for i := 0; i < n; i++ {
        ans = max(ans, dp[i])
	}
	return ans
}