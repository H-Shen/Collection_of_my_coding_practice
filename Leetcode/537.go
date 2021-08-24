func parse(s string) (int,int) {
	var i = 0
	var sb0, sb1 strings.Builder
	if s[0] == '-' {
		sb0.WriteRune('-')
		i++
	}
	for ; s[i] >= '0' && s[i] <= '9'; i++ {
		sb0.WriteRune(rune(s[i]))
	}
	i++
	if s[i] == '-' {
		sb1.WriteRune('-')
		i++
	}
	for ; s[i] >= '0' && s[i] <= '9'; i++ {
		sb1.WriteRune(rune(s[i]))
	}
	a, err := strconv.Atoi(sb0.String())
	if err != nil {
		os.Exit(1)
	}
	b, err := strconv.Atoi(sb1.String())
	if err != nil {
		os.Exit(1)
	}
	return a, b
}

func complexNumberMultiply(num1 string, num2 string) string {
	a, b := parse(num1)
	c, d := parse(num2)
	e := a*c - b*d
	f := b*c + a*d
	return strconv.Itoa(e) + "+" + strconv.Itoa(f) + "i"
}