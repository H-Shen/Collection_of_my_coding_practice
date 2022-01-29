var (
	// (x, y) --> (x + dx[i], y + dy[i])
	found bool
	dx = []int{1, -1, 0, 0}
	dy = []int{0, 0, -1, 1}
	n int
	m int
	Word string
)

func dfs(board [][]byte, vis [][]bool, i int, j int, index int) {
	// Base case 1:
	if found {
		return
	}
	// Base case 2:
	if index >= len(Word) {
		found = true
		return
	}
	var new_i, new_j int
	for step := 0; step < 4; step++ {
		new_i = i + dx[step]
		new_j = j + dy[step]
		if new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && board[new_i][new_j] == Word[index] && !vis[new_i][new_j] {
			vis[new_i][new_j] = true
			dfs(board, vis, new_i, new_j, index + 1)
			vis[new_i][new_j] = false
		}
	}
}

func exist(board [][]byte, word string) bool {
	found = false
	n = len(board)
	m = len(board[0])
	Word = word
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if board[i][j] == word[0] {
				if found {
					return found
				} else {
					vis := make([][]bool, n)
					for k := 0; k < n; k++ {
						vis[k] = make([]bool, m)
					}
					vis[i][j] = true
					dfs(board, vis, i, j, 1)
				}
			}
		}
	}
	return found
}