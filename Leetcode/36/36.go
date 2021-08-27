func isValidSudoku(board [][]byte) bool {
	const N int = 9
	for i := 0; i < N; i++ {
		var vis = [N+1]bool{}
		for j := 0; j < N; j++ {
			if board[i][j] >= '0' && board[i][j] <= '9' {
				if vis[board[i][j] - '0'] {
					return false
				}
				vis[board[i][j] - '0'] = true
			}
		}
	}
	for i := 0; i < N; i++ {
		var vis = [N+1]bool{}
		for j := 0; j < N; j++ {
			if board[j][i] >= '0' && board[j][i] <= '9' {
				if vis[board[j][i] - '0'] {
					return false
				}
				vis[board[j][i] - '0'] = true
			}
		}
	}
	for k := 0; k < N; k+=3 {
		for m := 0; m < N; m+=3 {
			var vis = [N+1]bool{}
			for i := k; i < k+3; i++ {
				for j := m; j < m+3; j++ {
					if board[i][j] >= '0' && board[i][j] <= '9' {
						if vis[board[i][j] - '0'] {
							return false
						}
						vis[board[i][j] - '0'] = true
					}
				}
			}
			
		}
	}
	return true
}