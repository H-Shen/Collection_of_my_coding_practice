const MOD int64 = 1e9 + 7

// D1 = 0
// D2 = 1
// Dn = (n-1)(D_(n-1)+D_(n-2))
func D(n int64) int64 {
	if n == 1 {
		return 0
	} else if n == 2 {
		return 1
	}
	var a int64 = 0
	var b int64 = 1
	var temp int64
	for i := int64(3); i <= n; i++ {
		temp = b
		b = (i-1)*(a+b) % MOD
		a = temp
	}
	return b % MOD
}
func findDerangement(n int) int {
	return int(D(int64(n)))
}