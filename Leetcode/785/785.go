var (
	hasAns bool
	color  []int	// 0/1/-1
)

func dfs(adj *[][]int, u int) {
	if !hasAns {
		return
	}
	if color[u] == 1 {
		for i := 0; i < len((*adj)[u]); i++ {
			v := (*adj)[u][i]
			if color[v] == 0 {
				color[v] = -1
				dfs(adj, v)
			} else if color[v] == 1 {
				hasAns = false
				return
			}
		}
	} else {
		for i := 0; i < len((*adj)[u]); i++ {
			v := (*adj)[u][i]
			if color[v] == 0 {
				color[v] = 1
				dfs(adj, v)
			} else if color[v] == -1 {
				hasAns = false
				return
			}
		}
	}
}

func isBipartite(graph [][]int) bool {
	hasAns = true
	color = nil
	n := len(graph)
	color = make([]int, n)
	for i := 0; i < n; i++ {
		if color[i] == 0 {
			color[i] = 1
			dfs(&graph, i)
		}
	}
	return hasAns
}