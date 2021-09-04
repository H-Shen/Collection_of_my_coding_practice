const MAXN int = 105
var pre [MAXN]int

func rangeSum(l, r int) int {
	if l == 0 {
		return pre[r]
	}
	return pre[r]-pre[l-1]
}
func findMiddleIndex(nums []int) int {
	if len(nums) == 1 {
		return 0
	}
	pre[0] = nums[0]
	for i := 1; i < len(nums); i++ {
		pre[i] = pre[i-1] + nums[i]
	}
	if rangeSum(1,len(nums)-1) == 0 {
		return 0
	}
	for i := 1; i < len(nums)-1; i++ {
		if rangeSum(0, i-1) == rangeSum(i+1,len(nums)-1) {
			return i
		}
	}
	if rangeSum(0,len(nums)-2) == 0 {
		return len(nums)-1
	}
	return -1
}