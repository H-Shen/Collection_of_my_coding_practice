func shiftingLetters(s string, shifts []int) string {
	const MAXN = 26
	pre := make([]int, len(shifts))
	pre[len(shifts)-1] = shifts[len(shifts)-1]
	for i := len(shifts)-2; i >= 0; i-- {
		pre[i] = pre[i+1] + shifts[i]
	}
	var sb strings.Builder
	sb.Grow(len(shifts))
	for i := 0; i < len(shifts); i++ {
		temp := pre[i] % 26
		ch := s[i]
		for j := 0; j < temp; j++ {
			if ch == 'z' {
				ch = 'a'
			} else {
				ch++
			}
		}
		sb.WriteRune(rune(ch))
	}
	return sb.String()
}