func detectCapitalUse(word string) bool {
	var s1 []rune
	for i := 0; i < len(word); i++ {
		s1 = append(s1, unicode.ToUpper(rune(word[i])))
	}
	var s2 []rune
	for i := 0; i < len(word); i++ {
		s2 = append(s2, unicode.ToLower(rune(word[i])))
	}
	var s3 []rune
	for i := 0; i < len(word); i++ {
		s3 = append(s3, s2[i])
	}
	s3[0] = unicode.ToUpper(s2[0])
	return word == string(s1) || word == string(s2) || word == string(s3)
}