func solve(A []int, B []int) int {
	unmap := make(map[int64]int)
	for i := 0; i < len(B)-1; i++ {
		for j := i+1; j < len(B); j++ {
			unmap[int64(B[i])*int64(B[j])]++
		}
	}
	ans := 0
	for _, v := range A {
		val, ok := unmap[int64(v)*int64(v)]
		if ok {
			ans += val
		}
	}
	return ans
}
func numTriplets(nums1 []int, nums2 []int) int {
	return solve(nums1, nums2) + solve(nums2, nums1)
}