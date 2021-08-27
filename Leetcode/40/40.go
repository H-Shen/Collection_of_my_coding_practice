func dfs(v []int, index int, sum int, target *int, candidates []int, ans *[][]int) {
	if sum == *target {
		*ans = append(*ans, v)
		return
	}
	for i := index; i < len(candidates); i++ {
		if i > index && candidates[i] == candidates[i-1] {
			continue
		}
		if sum + candidates[i] > *target {
			return
		}
		var temp = make([]int, len(v))
		copy(temp, v)
		temp = append(temp, candidates[i])
		dfs(temp, i+1, sum + candidates[i], target, candidates, ans)
	}
}
func combinationSum2(candidates []int, target int) [][]int {
	var ans[][]int
	sort.Ints(candidates)
	var emptySlice []int
	dfs(emptySlice, 0, 0, &target, candidates, &ans)
	return ans
}