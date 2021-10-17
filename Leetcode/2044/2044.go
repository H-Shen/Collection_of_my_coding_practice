func countMaxOrSubsets(nums []int) int {
	total := 1<<len(nums)
	maxVal := -1
	for i := 1; i < total; i++ {
		temp := i
		index := 0
		sum := -1
		for temp > 0 {
			if (temp & 1) != 0 {
				if sum == -1 {
					sum = nums[index]
				} else {
					sum |= nums[index]
				}
			}
			temp >>= 1
			index++
		}
		if sum > maxVal {
			maxVal = sum
		}
	}
	counter := 0
	for i := 1; i < total; i++ {
		temp := i
		index := 0
		sum := -1
		for temp > 0 {
			if (temp & 1) != 0 {
				if sum == -1 {
					sum = nums[index]
				} else {
					sum |= nums[index]
				}
			}
			temp >>= 1
			index++
		}
		if sum == maxVal {
			counter++
		}
	}
	return counter
}