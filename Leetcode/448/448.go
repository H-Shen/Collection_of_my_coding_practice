const EXIST = 0x3f3f3f3f

func restore(n int) int {
	if n >= EXIST {
		n -= EXIST
	}
	return n
}

func findDisappearedNumbers(nums []int) []int {
	n := len(nums)
	nums = append(nums, 0)
	for i := 0; i < n; i++ {
        if nums[restore(nums[i])] < EXIST {
			nums[restore(nums[i])] += EXIST
		}
	}
	var ans []int
	for i := 1; i <= n; i++ {
		if nums[i] < EXIST {
			ans = append(ans, i)
		}
	}
	return ans
}