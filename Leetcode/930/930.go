func numSubarraysWithSum(nums []int, goal int) int {
	const MAXN = 6e4 + 5
	pre := make([]int, len(nums)+1)
	for i := 1; i <= len(nums); i++ {
		pre[i] = pre[i-1] + nums[i-1]
	}
	var stats [MAXN][]int
	for i := 0; i < len(nums)+1; i++ {
		stats[pre[i]+goal] = append(stats[pre[i]+goal], i)
	}
	counter := 0
	for r := 0; r < len(nums)+1; r++ {
		if len(stats[pre[r]]) > 0 && r > stats[pre[r]][0] {
			pos := sort.Search(len(stats[pre[r]]), func(i int) bool {
				return stats[pre[r]][i] >= r
			})
			counter += pos
		}
	}
	return counter
}