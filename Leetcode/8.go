func myAtoi(s string) int {
	var r strings.Builder
	var i = 0
	for i < len(s) && s[i] == ' ' {
		i++
	}
	for i < len(s) && !(s[i] >= '0' && s[i] <= '9') {
		r.WriteRune(rune(s[i]))
		i++
	}
	for i < len(s) && (s[i] >= '0' && s[i] <= '9') {
		r.WriteRune(rune(s[i]))
		i++
	}
	var rString = r.String()
	var ans = new(big.Int)
	ans.SetString(rString, 10)
	var temp = new(big.Int)
	temp.SetInt64(math.MinInt32)
	if ans.Cmp(temp) < 0 {
		return math.MinInt32
	}
	temp.SetInt64(math.MaxInt32)
	if ans.Cmp(temp) > 0 {
		return math.MaxInt32
	}
	return int(ans.Int64())
}