func cmp(a *string, b *string) int {
	if len(*a) == len(*b) {
		for i := 0; i < len(*a); i++ {
			if (*a)[i] != (*b)[i] {
                if (*a)[i] > (*b)[i] {
                    return 1;
                } else {
                    return -1;
                }
			}
		}
		return 0
	} else if len(*a) > len(*b) {
		return 1
	}
	return -1
}
func kthLargestNumber(nums []string, k int) string {
	sort.Slice(nums, func(i, j int) bool {
		return cmp(&nums[i], &nums[j]) > 0
	})
    fmt.Println(nums)
	return nums[k-1]
}