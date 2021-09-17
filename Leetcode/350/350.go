func intersect(nums1 []int, nums2 []int) []int {
	map1 := make(map[int]int)
	for i := 0; i < len(nums1); i++ {
		map1[nums1[i]]++
	}
	map2 := make(map[int]int)
	for i := 0; i < len(nums2); i++ {
		map2[nums2[i]]++
	}
	var ans []int
	for k, val1 := range map1 {
		val2, ok := map2[k]
		if ok {
			if val1 > val2 {
				for i := 0; i < val2; i++ {
					ans = append(ans, k)
				}
			} else {
				for i := 0; i < val1; i++ {
					ans = append(ans, k)
				}
			}
		}
	}
	return ans
}