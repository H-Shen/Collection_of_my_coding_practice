func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func maxPower(s string) int {
	counter := 0
	var ch byte
	maxVal := 0
	for i := 0; i < len(s); i++ {
		if counter == 0 {
			ch = s[i]
			counter++
			continue
		}
		if s[i] == ch {
			counter++
		} else {
			maxVal = max(maxVal, counter)
			ch = s[i]
			counter = 1
		}
	}
	maxVal = max(maxVal, counter)
	return maxVal
}