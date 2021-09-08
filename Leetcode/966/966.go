func g(s *string) string {
	var sb strings.Builder
	sb.Grow(len(*s))
	for i := 0; i < len(*s); i++ {
		ch := unicode.ToLower(rune((*s)[i]))
		if ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' {
			sb.WriteRune('a')
		} else {
			sb.WriteRune(ch)
		}
	}
	return sb.String()
}

func spellchecker(wordlist []string, queries []string) []string {
	unset := make(map[string]struct{})
	empty := struct {}{}
	s := ""
	for i := 0; i < len(wordlist); i++ {
		s = wordlist[i]
		unset[s] = empty
	}
	unmap := make(map[string]string)
	for i := 0; i < len(wordlist); i++ {
		s = strings.ToLower(wordlist[i])
		_, ok := unmap[s]
		if !ok {
			unmap[s] = wordlist[i]
		}
	}
	unmap2 := make(map[string]string)
	for i := 0; i < len(wordlist); i++ {
		s = g(&wordlist[i])
		_, ok := unmap2[s]
		if !ok {
			unmap2[s] = wordlist[i]
		}
	}
	ans := make([]string, len(queries))
	for i := 0; i < len(queries); i++ {
		_, ok := unset[queries[i]]
		if ok {
			ans[i] = queries[i]
			continue
		}
		s = strings.ToLower(queries[i])
		val, ok := unmap[s]
		if ok {
			ans[i] = val
			continue
		}
		s = g(&queries[i])
		val, ok = unmap2[s]
		if ok {
			ans[i] = val
		}
	}
	return ans
}