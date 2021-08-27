func count(s []int, elem int) int {
	ans := 0
	for _, i := range s {
		if i == elem {
			ans++
		}
	}
	return ans
}
func dfs(v []int, graph *[][]int, ans *[][]int) {
	if v[len(v)-1] == len(*graph)-1 {
		*ans = append(*ans, v)
		return
	}
	for _, i := range (*graph)[v[len(v)-1]] {
		if count(v, i) == 0 {
			temp := make([]int, len(v))
            copy(temp, v)
			temp = append(temp, i)
			dfs(temp, graph, ans)
		}
	}
}
func allPathsSourceTarget(graph [][]int) [][]int {
	var v []int
	var ans [][]int
    v = append(v, 0)
	dfs(v, &graph, &ans)
	return ans
}