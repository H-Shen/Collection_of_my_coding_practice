func isPalindrome(x int) bool {
	if x < 0 || (x % 10 == 0 && x != 0) {
		return false
	}
	var xRev = 0
	for x > xRev {
		xRev = xRev*10 + x%10
		x /= 10
	}
	return x == xRev || x == xRev / 10
}