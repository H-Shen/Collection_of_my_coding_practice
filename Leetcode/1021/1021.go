func removeOuterParentheses(s string) string {
	const N = 1e5+5
	vis := make([]bool, N)
	var l int
	counter := 0
	for i := 0; i < len(s); i++ {
		if counter == 0 {
			l = i
		}
		if s[i] == '(' {
			counter++
		} else {
			counter--
			if counter == 0 {
				vis[l] = true
				vis[i] = true
			}
		}
	}
	var runes []rune
	for i := 0; i < len(s); i++ {
		if !vis[i] {
			runes = append(runes, rune(s[i]))
		}
	}
	return string(runes)
}