func minStartValue(nums []int) int {
	prefixSum := nums[0]
	minPrefixSum := prefixSum
	for i := 1; i < len(nums); i++ {
		prefixSum += nums[i]
		if prefixSum < minPrefixSum {
			minPrefixSum = prefixSum
		}
	}
	if minPrefixSum > 0 {
		return 1
	}
	return -minPrefixSum + 1
}