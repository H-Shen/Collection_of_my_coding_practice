func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func minimumDifference(nums []int, k int) int {
	sort.Ints(nums)
	ans := math.MaxInt32
	for i := 0; i + k - 1 < len(nums); i++ {
		ans = min(ans, nums[i+k-1]-nums[i])
	}
	return ans
}