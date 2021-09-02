func replaceWords(dictionary []string, sentence string) string {
	dict := make(map[string]struct{})
	temp := struct{}{}
	for i := 0; i < len(dictionary); i++ {
		dict[dictionary[i]] = temp
	}
	split := strings.Split(sentence, " ")
	for i := 0; i < len(split); i++ {
		var str []uint8
		for j := 0; j < len(split[i]); j++ {
			str = append(str, split[i][j])
			_, ok := dict[string(str)]
			if ok {
				split[i] = string(str)
				break
			}
		}
	}
	return strings.Join(split, " ")
}