func longestPalindrome(s string) string {
	longestLength := 0
	left, right := 0, 0
	// odd
	for i := 0; i < len(s); i++ {
		currentLength := 1
		for j, k := i-1, i+1; j >= 0 && k < len(s) && s[j] == s[k]; j, k = j-1, k+1 {
			currentLength = k - j + 1
			if currentLength > longestLength {
				longestLength = currentLength
				left = j
				right = k
			}
		}
	}
	// even
	for i := 0; i < len(s)-1; i++ {
		if s[i] == s[i+1] {
			currentLength := 2
			for j, k := i, i+1; j >= 0 && k < len(s) && s[j] == s[k]; j, k = j-1, k+1 {
				currentLength = k - j + 1
				if currentLength > longestLength {
					longestLength = currentLength
					left = j
					right = k
				}
			}
		}
	}
	return s[left:right+1]
}