type Pair struct {
	ch rune
	pos int
}

func reverseOnlyLetters(s string) string {
	var A []Pair
	for i := 0; i < len(s); i++ {
		if (s[i] >= 'a'&& s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') {
			A = append(A, Pair{pos: i, ch: rune(s[i])})	
		}
	}
	for i := 0; i < len(A)/2; i++ {
		A[i].ch, A[len(A)-1-i].ch = A[len(A)-1-i].ch, A[i].ch
	}
	runes := []rune(s)
	for i := 0; i < len(A); i++ {
		runes[A[i].pos] = A[i].ch
	}
	return string(runes)
}