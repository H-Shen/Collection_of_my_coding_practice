func wordSubsets(words1 []string, words2 []string) []string {
	const N = 26
	var freq [N]int
	for i := 0; i < len(words2); i++ {
		var freq2[N] int
		for j := 0; j < len(words2[i]); j++ {
			freq2[words2[i][j] - 'a']++
		}
		for j := 0; j < N; j++ {
			if freq2[j] > freq[j] {
				freq[j] = freq2[j]
			}
		}
	}
	var result []string
	for i := 0; i < len(words1); i++ {
		var freq2[N] int
		for j := 0; j < len(words1[i]); j++ {
			freq2[words1[i][j] - 'a']++
		}
		haveAns := true
		for j := 0; j < N; j++ {
			if freq2[j] < freq[j] {
				haveAns = false
				break
			}
		}
		if haveAns {
			result = append(result, words1[i])
		}
	}
	return result
}