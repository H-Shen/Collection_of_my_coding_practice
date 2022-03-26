func search(nums []int, target int) int {
	pos := sort.Search(len(nums), func(i int) bool {
		return nums[i] >= target
	})
	if pos == len(nums) || nums[pos] != target {
		return -1
	}
	return pos
}