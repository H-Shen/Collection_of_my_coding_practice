func rangeXorSum(pre []int, l, r int) int {
	if l == 1 {
		return pre[r]
	}
	return pre[l-1] ^ pre[r]
}
func xorQueries(arr []int, queries [][]int) []int {
	pre := make([]int, len(arr)+1)
	for i := 1; i <= len(arr); i++ {
		pre[i] = pre[i-1] ^ arr[i-1]
	}
	ans := make([]int, len(queries))
	for i := 0; i < len(queries); i++ {
		ans[i] = rangeXorSum(pre, queries[i][0]+1, queries[i][1]+1)
	}
	return ans
}