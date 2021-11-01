const (
	STEPS = 4
)
var (
	dx = [...]int{-1,1,0,0}
	dy = [...]int{0,0,-1,1}
)

// DSU
var (
	father []int
	Size []int
)

func initDsu(n int)  {
	father = make([]int, n+5)
	for i := 0; i < len(father); i++ {
		father[i] = i
	}
	Size = make([]int, n+5)
	for i := 0; i < len(Size); i++ {
		Size[i] = 1
	}
}
func find(x int) int {
	if x != father[x] {
		father[x] = find(father[x])
	}
	return father[x]
}
func merge(x, y int) {
	x = find(x)
	y = find(y)
	if x == y {
		return
	}
	if Size[x] > Size[y] {
		x, y = y, x
	}
	Size[y] += Size[x]
	father[x] = y
}

func solve(board [][]byte)  {
	n := len(board)
	m := len(board[0])
	initDsu(n*m)
	var newI, newJ int
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if board[i][j] == 'O' {
				for step := 0; step < STEPS; step++ {
					newI = i + dx[step]
					newJ = j + dy[step]
					if newI >= 0 && newI < n && newJ >= 0 && newJ < m && board[newI][newJ] == 'O' {
						merge(i*m+j, newI*m+newJ)
					}
				}
			}
		}
	}
	groups := make(map[int][]int)
	var groupId int
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if board[i][j] == 'O' {
				groupId = find(i*m+j)
				groups[groupId] = append(groups[groupId], i*m+j)
			}
		}
	}
	var haveAns bool
	var r, c int
	for _, nodeList := range groups {
		haveAns = true
		for i := 0; i < len(nodeList); i++ {
			r = nodeList[i]/m
			c = nodeList[i]%m
			if r == 0 || r == n-1 || c == 0 || c == m-1 {
				haveAns = false
				break
			}
		}
		if haveAns {
			for i := 0; i < len(nodeList); i++ {
				r = nodeList[i]/m
				c = nodeList[i]%m
				board[r][c] = 'X'
			}
		}
	}
}