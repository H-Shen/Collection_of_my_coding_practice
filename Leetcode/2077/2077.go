// O(n^3)
func numberOfPaths(n int, corridors [][]int) int {
	vis := make([][]bool, n+1)
	for i := 1; i <= n; i++ {
		vis[i] = make([]bool, n+1)
	}
	var u, v int
	for i := 0; i < len(corridors); i++ {
		u = corridors[i][0]
		v = corridors[i][1]
		vis[u][v] = true
		vis[v][u] = true
	}
	ans := 0
	for i := 1; i <= n-2; i++ {
		for j := i + 1; j <= n-1; j++ {
			if vis[i][j] {
				for k := j+1; k <= n ; k++ {
					if vis[i][k] && vis[k][j] {
						ans++
					}
				}
			}
		}
	}
	return ans
}