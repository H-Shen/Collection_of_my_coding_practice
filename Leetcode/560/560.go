func subarraySum(nums []int, k int) int {
	// pre[r] == pre[l-1] + k
	pre := make([]int, len(nums)+1)
	for i := 1; i <= len(nums); i++ {
		pre[i] = pre[i-1] + nums[i-1]
	}
	unmap := make(map[int][]int)
	counter := 0
	for i := 0; i <= len(nums); i++ {
		unmap[pre[i]] = append(unmap[pre[i]], i)
	}
	for i := 0; i <= len(nums); i++ {
		val, ok := unmap[pre[i]+k]
		if ok {
			temp := sort.Search(len(val), func(j int) bool {
				return val[j] > i
			})
			counter += len(val) - temp
		}
	}
	return counter
}