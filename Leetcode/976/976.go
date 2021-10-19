func largestPerimeter(nums []int) int {
	sort.Ints(nums)
	ans := 0
	for i := len(nums) - 1; i >= 2; i-- {
		if nums[i-2] + nums[i-1] > nums[i] {
			return nums[i-2] + nums[i-1] + nums[i]
		}
	}
	return ans
}