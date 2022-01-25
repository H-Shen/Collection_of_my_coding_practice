var (
	result []int
)


func dfs(num []rune, low int, high int) {
	s := string(num)
	val, err := strconv.Atoi(s)
	if err != nil {
		log.Fatalln(err)
	}
	if val > high {
		return
	}
	if val >= low && val <= high {
		result = append(result, val)
	}
	if num[len(num) - 1] == '9' {
		return
	}
	num = append(num, num[len(num)-1]+1)
	dfs(num, low, high)
}

func sequentialDigits(low int, high int) []int {
	result = nil
	for i := 1; i <= 9; i++ {
		var num []rune
		num = append(num, rune('0' + i))
		dfs(num, low, high)
	}
    sort.Ints(result)
	return result
}