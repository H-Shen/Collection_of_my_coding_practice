func shiftGrid(grid [][]int, k int) [][]int {
	var temp []int
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			temp = append(temp, grid[i][j])
		}
	}
	if k > len(temp) {
		k %= len(temp)
	}
	var temp2 []int
	for i := len(temp)-k; i < len(temp); i++ {
		temp2 = append(temp2, temp[i])
	}
	for i := 0; i < len(temp)-k; i++ {
		temp2 = append(temp2, temp[i])
	}
	pos := 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			grid[i][j] = temp2[pos]
			pos++
		}
	}
	return grid
}