const EXIST int = 0x3f3f3f3f

func restore(n int) int {
	if n > 2*EXIST {
		n -= 2*EXIST;
	} else if n > EXIST {
		n -= EXIST
	}
	return n
}
func findDuplicates(nums []int) []int {
	n := len(nums)
	nums = append(nums, 0)
	for i := 0; i < n; i++ {
		temp := restore(nums[i])
		nums[temp] += EXIST
	}
	var ans []int
	for i := 1; i <= n; i++ {
		if nums[i] >= 2*EXIST {
			ans = append(ans, i)
		}
	}
	return ans
}