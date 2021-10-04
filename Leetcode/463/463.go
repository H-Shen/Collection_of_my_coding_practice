const STEPS = 4

var (
	dx = [STEPS]int{0,0,-1,1}
	dy = [STEPS]int{-1,1,0,0}
	vis [][]bool
)

func dfs(i, j, n, m int, grid [][]int) {
	var newI, newJ int
	for step := 0; step < STEPS; step++ {
		newI = i + dx[step]
		newJ = j + dy[step]
		if newI >= 0 && newI < n && newJ >= 0 && newJ < m && grid[newI][newJ] == 1 && !vis[newI][newJ] {
			vis[newI][newJ] = true
			dfs(newI, newJ, n, m, grid)
		}
	}
}

func islandPerimeter(grid [][]int) int {
	n := len(grid)
	m := len(grid[0])
	vis = nil
	vis = make([][]bool, n)
	for i := 0; i < n; i++ {
		vis[i] = make([]bool, m)
	}
	flag := false
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] == 1 {
				vis[i][j] = true
				dfs(i, j, n, m, grid)
				flag = true
				break
			}
		}
		if flag {
			break
		}
	}
	ans := 0
	var newI, newJ int
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if vis[i][j] {
				for step := 0; step < STEPS; step++ {
					newI = i + dx[step]
					newJ = j + dy[step]
					if newI >= 0 && newI < n && newJ >= 0 && newJ < m {
						if grid[newI][newJ] == 0 {
							ans++
						}
					} else {
						ans++
					}
				}
			}
		}
	}
	return ans
}