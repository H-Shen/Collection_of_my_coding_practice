func missingNumber(nums []int) int {
	var sum = 0
	for _, i := range nums {
		sum += i
	}
	var n = len(nums)
	return (((0+n)*(n+1))>>1) - sum
}