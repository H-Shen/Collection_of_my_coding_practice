func solve(s *string) string {
	var runes []rune
	var i int
	ignore := false
	for i = 0; i < len(*s); i++ {
		if (*s)[i] == '@' {
			break
		}
		if !ignore {
			if (*s)[i] == '+' {
				ignore = true
			} else if (*s)[i] == '.' {
				continue
			} else {
				runes = append(runes, rune((*s)[i]))
			}
		}
	}
	for ; i < len(*s); i++ {
		runes = append(runes, rune((*s)[i]))
	}
	return string(runes)
}

func numUniqueEmails(emails []string) int {
	unmap := make(map[string]struct{})
	var empty struct{}
	for i := 0; i < len(emails); i++ {
		unmap[solve(&emails[i])] = empty
	}
	return len(unmap)
}