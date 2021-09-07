var (
	reach [][]bool
	dp []int
)

func solve(u int) int {
	if dp[u] != -1 {
		return dp[u]
	}
	dp[u] = 1
	var temp int
	for i := 0; i < len(dp); i++ {
		if i != u && reach[i][u] {
			temp = solve(i)+1
			if temp > dp[u] {
				dp[u] = temp
			}
		}
	}
	return dp[u]
}

func predecessor(a, b *string) bool {
	if len(*a) != len(*b)-1 {
		return false
	}
	flag := false
	for i, j := 0, 0; i < len(*a); {
		if (*a)[i] == (*b)[j] {
			i++
			j++
		} else {
			if flag {
				return false
			}
			flag = true
			j++
		}
	}
	return true
}

func longestStrChain(words []string) int {
	reach = nil
	reach = make([][]bool, len(words))
	for i := 0; i < len(words); i++ {
		reach[i] = make([]bool, len(words))
	}
	for i := 0; i < len(words)-1; i++ {
		for j := i+1; j < len(words); j++ {
			if predecessor(&words[i],&words[j]) {
				reach[i][j] = true
			}
			if predecessor(&words[j],&words[i]) {
				reach[j][i] = true
			}
		}
	}
	dp = nil
	dp = make([]int, len(words))
	for i := 0; i < len(words); i++ {
		dp[i] = -1
	}
	ans := 0
	var temp int
	for i := 0; i < len(words); i++ {
		temp = solve(i)
		if ans < temp {
			ans = temp
		}
	}
	return ans
}