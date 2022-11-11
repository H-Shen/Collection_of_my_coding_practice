func check(stack []uint8) bool {
	if len(stack) < 2 {
		return false
	}
	a := stack[len(stack)-1]
	b := stack[len(stack)-2]
	return a == b
}

func removeDuplicates(s string) string {
	var stack []uint8
	for i := 0; i < len(s); i++ {
		stack = append(stack, s[i])
		for ; check(stack); {
			stack = stack[:len(stack)-2]
		}
	}
	return string(stack)
}