func sortArrayByParityII(nums []int) []int {
	j := 1
	for i := 0; i < len(nums); i += 2 {
		if (nums[i] & 1) != 0 {
			for ; j < len(nums); j += 2 {
				if nums[j] & 1 == 0 {
					break
				}
			}
			nums[i], nums[j] = nums[j], nums[i]
		}
	}
	return nums
}