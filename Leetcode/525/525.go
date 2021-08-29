func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func findMaxLength(nums []int) int {
	pre := make([]int, len(nums)+1)
	for i := 1; i < len(pre); i++ {
		pre[i] = pre[i-1] + nums[i-1]
	}
	ans := 0
	unmap := make(map[int][]int)
	for i := 0; i < len(pre); i++ {
		unmap[(pre[i]<<1)-i] = append(unmap[(pre[i]<<1)-i], i)
	}
	for _, v := range unmap {
		if len(v) > 1 {
			ans = max(ans, v[len(v)-1]-v[0])
		}
	}
	return ans
}