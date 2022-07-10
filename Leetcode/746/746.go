const (
	INF = 0x3f3f3f3f
	MAXN = 1005
)

var dp [MAXN]int 

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func solve(i int, cost []int) int {
	if dp[i] != INF {
		return dp[i]
	}
	dp[i] = min(solve(i-2, cost)+cost[i-2], solve(i-1, cost)+cost[i-1])
	return dp[i]
}

func minCostClimbingStairs(cost []int) int {
	for i := 0; i < MAXN; i++ {
		dp[i] = INF
	}
	dp[0] = 0
	dp[1] = 0
	return solve(len(cost), cost)
}