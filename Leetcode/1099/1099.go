func twoSumLessThanK(nums []int, k int) int {
	sort.Ints(nums)
	i, j := 0, len(nums)-1
	sum := -1
	for i < j {
		temp := nums[i] + nums[j]
		if temp >= k {
			j--
		} else {
			if sum < temp {
				sum = temp
			}
			i++
		}
	}
	return sum
}