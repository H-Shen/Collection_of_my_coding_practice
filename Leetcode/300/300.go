// O(n^2)
func lengthOfLIS(nums []int) int {
	n := len(nums)
	dp := make([]int, n)
    for i := 0; i < n; i++ {
        dp[i] = 1
    }
	for i := 1; i < n; i++ {
		for j := 0; j < i; j++ {
			if nums[j] < nums[i] {
				if dp[i] < dp[j] + 1 {
					dp[i] = dp[j] + 1
				} 
			}
		}
	}
	ans := 0
	for i := 0; i < n; i++ {
		if dp[i] > ans {
			ans = dp[i]
		}
	}
	return ans
}