func judgeSquareSum(c int) bool {
	var c64 = int64(c)
	for i := int64(0); i * i <= c64; i++ {
		var j = int64(math.Sqrt(float64(c64 - i * i)))
		if j * j + i * i == c64 {
			return true
		}
	}
	return false
}