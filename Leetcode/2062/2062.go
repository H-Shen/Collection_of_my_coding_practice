func check(runes []rune, l int, r int) bool {
	const N = 5
	stats := [N]int{}
	for i := l; i <= r; i++ {
		switch runes[i] {
		case 'a':
			stats[0]++
		case 'e':
			stats[1]++
		case 'i':
			stats[2]++
		case 'o':
			stats[3]++
		case 'u':
			stats[4]++
		default:
			return false
		}
	}
    for j := 0; j < N; j++ {
        if stats[j] == 0 {
            return false
        }
    }
	return true
}
func countVowelSubstrings(word string) int {
	runes := []rune(word)
	counter := 0
	for i := 0; i < len(runes); i++ {
		for j := i; j < len(runes); j++ {
			if check(runes, i, j) {
				counter++
			}
		}
	}
	return counter
}