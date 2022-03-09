func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func increasingTriplet(nums []int) bool {
	if len(nums) <= 2 {
		return false
	}
	maxFromRight := make([]int, len(nums))
	maxFromRight[len(nums)-1] = nums[len(nums)-1]
	for i := len(nums)-2; i >= 0; i-- {
		maxFromRight[i] = max(maxFromRight[i+1], nums[i])
	}
	minFromLeft := nums[0]
	for i := 1; i < len(nums)-1; i++ {
		if minFromLeft < nums[i] && nums[i] < maxFromRight[i+1] {
			return true
		}
		minFromLeft = min(minFromLeft, nums[i])
	}
	return false
}