func reverseWords(s string) string {
	r := regexp.MustCompile("[^\\s]+")
	result := r.FindAllString(s, -1)
	half := len(result) / 2
	for i := 0; i < half; i++ {
		result[i], result[len(result)-1-i] = result[len(result)-1-i], result[i]
	}
	return strings.Join(result, " ")
}