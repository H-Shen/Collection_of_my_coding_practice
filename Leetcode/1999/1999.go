func dfs(cur int, d1 int, d2 int, k int, ans *int)  {
	if cur > math.MaxInt32 {
		return
	}
	if cur > k && cur % k == 0 {
		if *ans > cur {
			*ans = cur
		}
		return
	}
	dfs(cur * 10 + d1, d1, d2, k, ans)
	dfs(cur * 10 + d2, d1, d2, k, ans)
}

func findInteger(k int, digit1 int, digit2 int) int {
	const INF int = math.MaxInt32+5
	if digit1 == 0 && digit2 == 0 {
		return -1
	}
	ans := INF
	if digit1 == 0 {
		dfs(digit2, digit1, digit2, k, &ans)
	} else if digit2 == 0 {
		dfs(digit1, digit1, digit2, k, &ans)
	} else {
		dfs(digit1, digit1, digit2, k, &ans)
		dfs(digit2, digit1, digit2, k, &ans)
	}
	if ans == INF {
		return -1
	}
	return ans
}