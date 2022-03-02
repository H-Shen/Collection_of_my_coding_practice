func countBits(n int) []int {
	// dp(0) = 0
	// dp(1) = 1
	// dp(n) = dp(n&(n-1)) + 1
	dp := make([]int, n+1)
	dp[0] = 0
	if n >= 1 {
		dp[1] = 1
		for i := 2; i <= n; i++ {
			dp[i] = dp[i&(i-1)] + 1
		}
	}
	return dp
}