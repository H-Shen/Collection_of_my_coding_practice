func finalValueAfterOperations(operations []string) int {
	x := 0
	for i := 0; i < len(operations); i++ {
		if operations[i][0] == '-' || operations[i][2] == '-' {
			x--
		} else {
			x++
		}
	}
	return x
}