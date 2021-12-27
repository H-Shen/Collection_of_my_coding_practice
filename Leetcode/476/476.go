func findComplement(num int) int {
	var a []int
	for num > 0 {
		if num&1 != 0 {
			a = append(a, 1)
		} else {
			a = append(a, 0)
		}
		num >>= 1
	}
	for i := 0; i < len(a); i++ {
		a[i] = 1 - a[i]
	}
	ans := 0
	val := 1
    for i := 0; i < len(a); i++ {
		ans += val * a[i]
		val <<= 1
	}
	return ans
}