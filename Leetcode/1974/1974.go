func dist(a, b rune) int {
	ans := math.MaxInt32
	counter := 0
	c := a
	for c != b {
		if c == 'z' {
			c = 'a'
		} else {
			c++
		}
		counter++
	}
	if ans > counter {
		ans = counter
	}
	counter = 0
	c = a
	for c != b {
		if c == 'a' {
			c = 'z'
		} else {
			c--
		}
		counter++
	}
	if ans > counter {
		ans = counter
	}
	return ans
}
func minTimeToType(word string) int {
	sum := 0
	ch := 'a'
	for _, i := range word {
		sum += dist(ch, i) + 1
		ch = i
	}
	return sum
}