func fourSumCount(nums1 []int, nums2 []int, nums3 []int, nums4 []int) int {
	n := len(nums1)
	unmap1 := make(map[int]int)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			unmap1[nums1[i]+nums2[j]]++
		}
	}
	unmap2 := make(map[int]int)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			unmap2[nums3[i]+nums4[j]]++
		}
	}
	counter := 0
	for k, v := range unmap1 {
		v2, ok := unmap2[-k]
		if ok {
			counter += v * v2
		}
	}
	return counter
}