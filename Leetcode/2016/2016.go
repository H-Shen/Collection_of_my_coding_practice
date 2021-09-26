func maximumDifference(nums []int) int {
	ans := -1
	for i := 0; i < len(nums)-1; i++ {
		for j := i+1; j < len(nums); j++ {
			if nums[i] < nums[j] {
				temp := nums[j] - nums[i]
				if temp > ans {
					ans = temp
				}
			}
		}
	}
	return ans
}