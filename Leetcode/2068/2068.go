func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func checkAlmostEquivalent(word1 string, word2 string) bool {
	const N = 26
	freq1 := make([]int, N)
	freq2 := make([]int, N)
	for i := 0; i < len(word1); i++ {
		freq1[word1[i]-'a']++
	}
	for i := 0; i < len(word2); i++ {
		freq2[word2[i]-'a']++
	}
	const THRESHOLD = 3
	for i := 0; i < N; i++ {
		if abs(freq1[i] - freq2[i]) > THRESHOLD {
			return false
		}
	}
	return true
}