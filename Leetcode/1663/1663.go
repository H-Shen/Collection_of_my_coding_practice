func getSmallestString(n int, k int) string {
	s := make([]rune, n)
	for i := 0; i < n; i++ {
		s[i] = 'a'
	}
	index := n-1
	sum := n
	for sum < k {
		if sum + 25 <= k {
			s[index] = 'z'
			index--
			sum += 25
		} else {
			s[index] += rune(k - sum)
			break
		}
	}
	return string(s)
}