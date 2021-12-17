func rangeSum(pre [][]int, r1, c1, r2, c2 int) int {
	if r1 == 0 && c1 == 0 {
		return pre[r2][c2]
	} else if r1 == 0 && c1 != 0 {
		return pre[r2][c2] - pre[r2][c1-1]
	} else if r1 != 0 && c1 == 0 {
		return pre[r2][c2] - pre[r1-1][c2]
	}
	return pre[r2][c2] - pre[r1-1][c2] - pre[r2][c1-1] + pre[r1-1][c1-1]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func maximalSquare(matrix [][]byte) int {
	n := len(matrix)
	m := len(matrix[0])
	pre := make([][]int, n)
	for i := 0; i < n; i++ {
		pre[i] = make([]int, m)
	}
	pre[0][0] = int(matrix[0][0] - '0')
	for i := 1; i < n; i++ {
		pre[i][0] = int(matrix[i][0]-'0') + pre[i-1][0]
	}
	for i := 1; i < m; i++ {
		pre[0][i] = int(matrix[0][i]-'0') + pre[0][i-1]
	}
	for i := 1; i < n; i++ {
		for j := 1; j < m; j++ {
			pre[i][j] = pre[i][j-1] + pre[i-1][j] - pre[i-1][j-1] + int(matrix[i][j]-'0')
		}
	}
	maxSide := 1
    hasAns := false
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
            for side := min(n - i, m - j); side >= maxSide; side-- {
				if rangeSum(pre, i, j, i+side-1, j+side-1) == side*side {
                    hasAns = true
					if maxSide < side {
						maxSide = side
					}
					break
				}
			}
		}
	}
    if !hasAns {
        return 0
    }
	return maxSide * maxSide
}