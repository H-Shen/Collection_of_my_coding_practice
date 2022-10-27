func arrayStringsAreEqual(word1 []string, word2 []string) bool {
	var a string
	for _, s := range word1 {
		a += s
	}
	var b string
	for _, s := range word2 {
		b += s
	}
	return a == b
}