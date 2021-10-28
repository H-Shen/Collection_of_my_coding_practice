func sortColors(nums []int)  {
	a, b, c := 0, 0, 0
	for i := 0; i < len(nums); i++ {
		if nums[i] == 0 {
			a++
		} else if nums[i] == 1 {
			b++
		} else {
			c++
		}
	}
	index := 0
	for a > 0 {
		nums[index] = 0
		index++
		a--
	}
	for b > 0 {
		nums[index] = 1
		index++
		b--
	}
	for c > 0 {
		nums[index] = 2
		index++
		c--
	}
}