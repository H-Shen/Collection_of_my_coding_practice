func productExceptSelf(nums []int) []int {
	preFromLeft := make([]int, len(nums))
	preFromLeft[0] = nums[0]
	for i := 1; i < len(nums); i++ {
		preFromLeft[i] = preFromLeft[i-1] * nums[i]
	}
	preFromRight := make([]int, len(nums))
	preFromRight[len(nums)-1] = nums[len(nums)-1]
	for i := len(nums)-2; i >= 0; i-- {
		preFromRight[i] = preFromRight[i+1] * nums[i]
	}
	answer := make([]int, len(nums))
	answer[0] = preFromRight[1]
	answer[len(nums)-1] = preFromLeft[len(nums)-2]
	for i := 1; i < len(nums)-1; i++ {
		answer[i] = preFromLeft[i-1]*preFromRight[i+1]
	}
	return answer
}