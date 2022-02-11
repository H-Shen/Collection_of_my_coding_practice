const MAXN = 26

func includes(stats1 [MAXN]int,  stats2 [MAXN]int) bool {
	for i := 0; i < MAXN; i++ {
		if stats1[i] > stats2[i] {
			return false
		}
	}
	return true
}

func checkInclusion(s1 string, s2 string) bool {
	if len(s1) > len(s2) {
		return false
	}
	var stats1 [MAXN]int
	for i := 0; i < len(s1); i++ {
		stats1[s1[i]-'a']++
	}
	var stats2 [MAXN]int
	for i := 0; i < len(s1); i++ {
		stats2[s2[i]-'a']++
	}
	if includes(stats1, stats2) {
		return true
	}
	for i, j := len(s1), 0; i < len(s2); i, j = i+1, j+1 {
		stats2[s2[j]-'a']--
		stats2[s2[i]-'a']++
		if includes(stats1, stats2) {
			return true
		}
	}
	return false
}