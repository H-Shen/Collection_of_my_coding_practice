func widestPairOfIndices(nums1 []int, nums2 []int) int {
	pre1 := make([]int, len(nums1)+1)
	for i := 1; i < len(nums1)+1; i++ {
		pre1[i] = pre1[i-1] + nums1[i-1]
	}
	pre2 := make([]int, len(nums2)+1)
	for i := 1; i < len(nums2)+1; i++ {
		pre2[i] = pre2[i-1] + nums2[i-1]
	}
	unmap := make(map[int][]int)
	for i := 0; i < len(nums1)+1; i++ {
		unmap[pre1[i]-pre2[i]] = append(unmap[pre1[i]-pre2[i]], i)
	}
	ans := 0
	for _, v := range unmap {
		if len(v) > 1 {
			if ans < v[len(v)-1]-v[0] {
				ans = v[len(v)-1]-v[0]
			}
		}
	}
	return ans
}