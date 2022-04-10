func calPoints(ops []string) int {
	var records []int
	for i := 0; i < len(ops); i++ {
		if ops[i][0] == '+' {
			records = append(records, records[len(records)-1] + records[len(records)-2])
		} else if ops[i][0] == 'D' {
			records = append(records, 2 * records[len(records)-1])
		} else if ops[i][0] == 'C' {
			records = records[:len(records)-1]
		} else {
			val, err := strconv.Atoi(ops[i])
			if err != nil {
				log.Fatalln(err)
			}
			records = append(records, val)
		}
	}
	sum := 0
	for i := 0; i < len(records); i++ {
		sum += records[i]
	}
	return sum
}