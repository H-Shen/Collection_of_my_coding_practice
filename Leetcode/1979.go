func gcd(x, y int) int {
	if x == 0 || y == 0 {
		return x + y
	}
	return gcd(y, x % y)
}
func findGCD(nums []int) int {
	minVal, maxVal := math.MaxInt32, math.MinInt32
	for _, num := range nums {
		if num < minVal {
			minVal = num
		}
		if num > maxVal {
			maxVal = num
		}
	}
	return gcd(minVal, maxVal)
}