func f(n int) []bool {
	var ans []bool
	for n > 0 {
		if n & 1 != 0 {
			ans = append(ans, true)
		} else {
			ans = append(ans, false)
		}
		n >>= 1
	}
	return ans
}

func hammingDistance(x int, y int) int {
	a := f(x)
	b := f(y)
	var maxVal int
	if len(a) > len(b) {
		maxVal = len(a)
	} else {
		maxVal = len(b)
	}
	for len(a) != maxVal {
		a = append(a, false)
	}
	for len(b) != maxVal {
		b = append(b, false)
	}
	counter := 0
	for i := 0; i < maxVal; i++ {
		if a[i] != b[i] {
			counter++
		}
	}
	return counter
}