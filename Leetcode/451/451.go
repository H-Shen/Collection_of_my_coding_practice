func frequencySort(s string) string {
	stats := make(map[uint8]int)
	for i := 0; i < len(s); i++ {
		stats[s[i]]++
	}
	arr := make([]uint8, len(s))
	for i := 0; i < len(s); i++ {
		arr[i] = s[i]
	}
	sort.Slice(arr, func(i, j int) bool {
		if stats[arr[i]] == stats[arr[j]] {
			return arr[i] < arr[j]
		}
		return stats[arr[i]] > stats[arr[j]]
	})
	return string(arr)
}