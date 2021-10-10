func twoOutOfThree(nums1 []int, nums2 []int, nums3 []int) []int {
	const N = 105
	vis1 := [N]bool{}
	vis2 := [N]bool{}
	vis3 := [N]bool{}
	for i := 0; i < len(nums1); i++ {
		vis1[nums1[i]] = true
	}
	for i := 0; i < len(nums2); i++ {
		vis2[nums2[i]] = true
	}
	for i := 0; i < len(nums3); i++ {
		vis3[nums3[i]] = true
	}
	var ans []int
	for i := 0; i < N; i++ {
		if (vis1[i] && vis2[i]) || (vis1[i] && vis3[i]) || (vis3[i] && vis2[i]) {
			ans = append(ans, i)
		}
	}
	return ans
}