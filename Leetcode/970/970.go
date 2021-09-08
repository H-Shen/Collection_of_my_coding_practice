func powerfulIntegers(x int, y int, bound int) []int {
	var ans []int
	if x == 1 && y == 1 {
		if bound >= 2 {
			ans = append(ans, 2)
		}
	} else if x == 1 {
		if bound >= 1 {
			temp := 1
			for x + temp <= bound {
				ans = append(ans, x + temp)
				temp *= y
			}
		}
	} else if y == 1 {
		return powerfulIntegers(y, x, bound)
	} else {
		temp := struct {}{}
		unset := make(map[int]struct{})
		for i := 1; i <= bound; i*=x {
			for j := 1; j+i <= bound; j*=y {
				unset[j+i] = temp
			}
		}
		for k := range unset {
			ans = append(ans, k)
		}
	}
	return ans
}