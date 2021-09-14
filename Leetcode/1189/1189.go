func min(a ... int) int {
	ans := math.MaxInt32
	for _, i := range a {
		if i < ans {
			ans = i
		}
	}
	return ans
}

func maxNumberOfBalloons(text string) int {
	const MAXN = 26
	var freq [MAXN]int
	for i := 0; i < len(text); i++ {
		freq[text[i]-'a']++
	}
	minVal := math.MaxInt32
	const STR = "balloon"
	if freq['b'-'a'] < 1 || freq['a'-'a'] < 1 || freq['l'-'a'] < 2 || freq['o'-'a'] < 2 || freq['n'-'a'] < 1 {
		return 0
	}
	minVal = min(minVal, freq['b'-'a'], freq['a'-'a'], freq['l'-'a']>>1, freq['o'-'a']>>1, freq['n'-'a'])
	return minVal
}