func twoSumLessThanK(nums []int, r int, k int) int {
	i, j := 0, r
	counter := 0
	for i < j {
		temp := nums[i] + nums[j]
		if temp >= k {
			j--
		} else {
			counter += j - i
			i++
		}
	}
	return counter
}

func threeSumSmaller(nums []int, target int) int {
	if len(nums) < 3 {
		return 0
	}
	sort.Ints(nums)
	counter := 0
	for k := 2; k < len(nums); k++ {
        // nums[i] + nums[j] < target - nums[k]
		counter += twoSumLessThanK(nums, k-1, target - nums[k])
	}
	return counter
}