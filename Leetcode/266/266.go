func canPermutePalindrome(s string) bool {
	const MAXN = 26
	stats := [MAXN]int{}
	for i := 0; i < len(s); i++ {
		stats[s[i] - 'a']++
	}
	counter := 0
	for i := 0; i < MAXN; i++ {
		if (stats[i] & 1) != 0 {
			counter++
			if counter > 1 {
				return false
			}
		}
	}
	return true
}