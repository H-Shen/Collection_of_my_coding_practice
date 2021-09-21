func findMaxConsecutiveOnes(nums []int) int {
	startIndex := -1
	ans := 0
	for endIndex := 0; endIndex < len(nums); endIndex++ {
		if nums[endIndex] == 1 {
			if startIndex == -1 {
				startIndex = endIndex
			}
		} else {
			if startIndex != -1 {
				if endIndex - startIndex > ans {
					ans = endIndex - startIndex
				}
				startIndex = -1
			}
		}
	}
	if startIndex != -1 && len(nums) - startIndex > ans {
		ans = len(nums) - startIndex
	}
	return ans
}