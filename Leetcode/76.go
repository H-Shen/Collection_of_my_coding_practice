func minWindow(s string, t string) string {
	const MAXN int = 128
	var stats [MAXN]int
	for _, ch := range t {
		stats[ch]++
	}
	var frontIndex int
	var stats2 [MAXN]int
	var minLength = math.MaxInt32
	var lastIndexOfMinLength = -1
	var flag bool
	for i := 0; i < len(s); i++ {
		stats2[s[i]]++
		for ; frontIndex <= i && stats2[s[frontIndex]] > stats[s[frontIndex]]; frontIndex++ {
			stats2[s[frontIndex]]--
		}
		flag = true
		for ch := 'a'; ch <= 'z'; ch++ {
			if stats2[ch] < stats[ch] {
				flag = false
				break
			}
		}
		if flag {
			for ch := 'A'; ch <= 'Z'; ch++ {
				if stats2[ch] < stats[ch] {
					flag = false
					break
				}
			}
		}
		if flag && minLength > i-frontIndex+1 {
			minLength = i - frontIndex + 1
			lastIndexOfMinLength = i
		}
	}
	if lastIndexOfMinLength == -1 {
		return ""
	}
	return s[lastIndexOfMinLength-minLength+1 : lastIndexOfMinLength+1]
}