func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maximumWealth(accounts [][]int) int {
	ans := -1
	for i := 0; i < len(accounts); i++ {
		sum := 0
		for j := 0; j < len(accounts[i]); j++ {
			sum += accounts[i][j]
		}
		ans = max(ans, sum)
	}
	return ans
}
