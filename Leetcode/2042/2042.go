func areNumbersAscending(s string) bool {
	arr := strings.Split(s, " ")
	var ans []int
	for i := 0; i < len(arr); i++ {
		temp, err := strconv.Atoi(arr[i])
		if err == nil {
			ans = append(ans, temp)
		}
	}
	if len(ans) <= 1 {
		return true
	}
	for i := 1; i < len(ans); i++ {
		if ans[i-1] >= ans[i] {
			return false
		}
	}
	return true
}