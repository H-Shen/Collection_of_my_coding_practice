func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func solve(from, to int) int {
	if from == to {
		return 0
	}
	if abs(from - to) % 2 == 0 {
		return 0
	}
	return 1
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func minCostToMoveChips(position []int) int {
	minCost := math.MaxInt32
	for i := 0; i < len(position); i++ {
		sum := 0
		for j := 0; j < len(position); j++ {
			sum += solve(position[j], position[i])
		}
		minCost = min(minCost, sum)
	}
	return minCost
}