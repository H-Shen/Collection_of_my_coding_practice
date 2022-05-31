func hasAllCodes(s string, k int) bool {
	tot := (1 << k) - 1
	vis := make([]bool, tot+1)
	counter := 0
	for i := 0; i+k <= len(s); i++ {
		val, _ := strconv.ParseInt(s[i : i+k], 2, 64)
		if !vis[val] {
			vis[val] = true
			counter++
		}
	}
	return counter == (1<<k)
}