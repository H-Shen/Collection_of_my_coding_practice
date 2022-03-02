func isSubsequence(s string, t string) bool {
	j := 0
	for i := 0; i < len(s); {
		if j == len(t) {
			return false
		}
		if t[j] == s[i] {
			i++
		}
		j++
	}
	return true
}