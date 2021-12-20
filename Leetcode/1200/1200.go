func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func minimumAbsDifference(arr []int) [][]int {
	sort.Ints(arr)
	minDiff := math.MaxInt32
	for i := 1; i < len(arr); i++ {
		minDiff = min(minDiff, arr[i]-arr[i-1])
	}
	unmap := make(map[int]struct{})
	value := struct {
	}{}
	for i := 0; i < len(arr); i++ {
		unmap[arr[i]] = value
	}
	var ans [][]int
	for i := 0; i < len(arr); i++ {
		_, ok := unmap[arr[i]+minDiff]
		if ok {
			ans = append(ans, []int{arr[i], arr[i]+minDiff})
		}
	}
	return ans
}