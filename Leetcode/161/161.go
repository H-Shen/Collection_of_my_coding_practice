func f(long *string, short *string) bool {
	var i = 0
	for i = 0; i < len(*short); i++ {
		if (*long)[i] != (*short)[i] {
			break
		}
	}
	i++
	for ; i < len(*long); i++ {
		if (*long)[i] != (*short)[i-1] {
			return false
		}
	}
	return true
}
func isOneEditDistance(s string, t string) bool {
	if len(s) == len(t) {
		diff := 0
		for i := 0; i < len(s); i++ {
			if s[i] != t[i] {
				diff++
				if diff > 1 {
					break
				}
			}
		}
		return diff == 1
	} else if len(s) - len(t) == 1 {
		return f(&s, &t)
	} else if len(t) - len(s) == 1 {
		return f(&t, &s)
	}
	return false
}