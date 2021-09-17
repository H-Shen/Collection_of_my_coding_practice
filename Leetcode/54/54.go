func spiralOrder(matrix [][]int) []int {
	n := len(matrix)
	m := len(matrix[0])
	vis := make([][]bool, n)
	for i := 0; i < n; i++ {
		vis[i] = make([]bool, m)
	}
	const STEPS = 4
	dx := [...]int{0,1,0,-1}
	dy := [...]int{1,0,-1,0}
	dir := 0
	counter := 1
	i, j := 0, 0
	ans := make([]int, n*m)
	for counter <= n * m {
		ans[counter-1] = matrix[i][j]
		vis[i][j] = true
		newI := i + dx[dir]
		newJ := j + dy[dir]
		if newI >= 0 && newI < n && newJ >= 0 && newJ < m && !vis[newI][newJ] {
			i = newI
			j = newJ
		} else {
			dir++
			if dir >= STEPS {
				dir = 0
			}
			i += dx[dir]
			j += dy[dir]
		}
		counter++
	}
	return ans
}