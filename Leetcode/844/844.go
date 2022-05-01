func getRunes(s string) []rune {
	var result []rune
	for i := 0; i < len(s); i++ {
		if s[i] == '#' {
			if len(result) > 0 {
				result = result[:len(result)-1]
			}
		} else {
			result = append(result, rune(s[i]))
		}
	}
    return result
}

func backspaceCompare(s string, t string) bool {
	a := getRunes(s)
	b := getRunes(t)
	if len(a) == len(b) {
		for i := 0; i < len(a); i++ {
			if a[i] != b[i] {
				return false
			}
		}
		return true
	}
	return false
}