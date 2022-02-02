func isAnagram(a, b [26]int) bool {
	for i := 0; i < 26; i++ {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

func findAnagrams(s string, p string) []int {
	var ans []int
	if len(s) < len(p) {
		return ans
	}
	var stats [26]int
	for i := 0; i < len(p); i++ {
		stats[p[i] - 'a']++
	}
	var currentStats [26]int
	for i := 0; i < len(p); i++ {
		currentStats[s[i] - 'a']++
	}
	if isAnagram(currentStats, stats) {
		ans = append(ans, 0)
	}
	for i,j := 0,len(p); j < len(s); i, j = i+1, j+1 {
		currentStats[s[j] - 'a']++
		currentStats[s[i] - 'a']--
		if isAnagram(currentStats, stats) {
			ans = append(ans, i+1)
		}
	}
	return ans
}