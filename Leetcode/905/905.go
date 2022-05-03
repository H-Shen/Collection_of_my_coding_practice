func sortArrayByParity(nums []int) []int {
	var odd []int
	var even []int
	for i := 0; i < len(nums); i++ {
		if (nums[i] & 1) == 0 {
			even = append(even, nums[i])
		} else {
			odd = append(odd, nums[i])
		}
	}
	pos := 0
	for i := 0; i < len(even); i++ {
		nums[pos] = even[i]
		pos++
	}
	for j := 0; j < len(odd); j++ {
		nums[pos] = odd[j]
		pos++
	}
	return nums
}
