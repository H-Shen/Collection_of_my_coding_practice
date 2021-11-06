func arrangeCoins(n int) int {
	sum := 0
	counter := 0
	for {
		sum += counter
		counter++
		if sum == n {
			return counter
		} else if sum > n {
			return counter - 1
		}
	}
}