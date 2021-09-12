func reversePrefix(word string, ch byte) string {
	pos := -1
	for i := 0; i < len(word); i++ {
		if word[i] == ch {
			pos = i
			break
		}
	}
	if pos == -1 {
		return word
	}
	runes := []rune(word[:pos+1])
	for i := 0; i < len(runes)/2; i++ {
		runes[i], runes[len(runes)-i-1] = runes[len(runes)-i-1], runes[i]
	}
	for i := pos+1; i < len(word); i++ {
		runes = append(runes, rune(word[i]))
	}
	return string(runes)
}