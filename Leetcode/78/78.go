func g(n int, nums []int) []int {
	var s []int
	for n > 0 {
		if (n & 1) != 0 {
			s = append(s, 1)
		} else {
			s = append(s, 0)
		}
		n >>= 1
	}
	for len(s) < len(nums) {
		s = append(s, 0)
	}
	var res []int
	for i := 0; i < len(nums); i++ {
		if s[i] == 1 {
			res = append(res, nums[i])
		}
	}
	return res
}
func subsets(nums []int) [][]int {
	n := len(nums)
	tot := 1 << n
	var res [][]int
	for i := 0; i < tot; i++ {
		res = append(res, g(i, nums))
	}
	return res
}