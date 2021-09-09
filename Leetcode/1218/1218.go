func longestSubsequence(arr []int, difference int) int {
	unmap := make(map[int][]int)
	dp := make([]int, len(arr))
	for i := 0; i < len(dp); i++ {
		dp[i] = 1
	}
	ans := 0
	for i := 0; i < len(dp); i++ {
		temp := arr[i] - difference
		val, ok := unmap[temp]
		if ok && i > val[0] {
			pos := sort.Search(len(val), func(j int) bool {
				return val[j] >= i
			})
			pos--
			dp[i] = dp[val[pos]] + 1
		}
		unmap[arr[i]] = append(unmap[arr[i]], i)
		if ans < dp[i] {
			ans = dp[i]
		}
	}
	return ans
}