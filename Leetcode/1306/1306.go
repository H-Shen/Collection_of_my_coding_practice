var (
	vis []bool
	n   int
	ans bool
)

func dfs(pos int, arr []int) {
	if ans {
		return
	}
	if arr[pos] == 0 {
		ans = true
		return
	}
	vis[pos] = true
	newPos := pos + arr[pos]
	if newPos >= 0 && newPos < n && !vis[newPos] {
		dfs(newPos, arr)
	}
	newPos = pos - arr[pos]
	if newPos >= 0 && newPos < n && !vis[newPos] {
		dfs(newPos, arr)
	}
}

func canReach(arr []int, start int) bool {
	n = len(arr)
	vis = make([]bool, n)
	ans = false
	dfs(start, arr)
	return ans
}