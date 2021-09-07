func slowestKey(releaseTimes []int, keysPressed string) byte {
	const MAXN = 26
	var stats [MAXN]int
	for i := 0; i < len(keysPressed); i++ {
		if i == 0 {
			stats[keysPressed[i] - 'a'] = releaseTimes[i]
			continue
		}
		if stats[keysPressed[i] - 'a'] < releaseTimes[i] - releaseTimes[i-1] {
			stats[keysPressed[i] - 'a'] = releaseTimes[i] - releaseTimes[i-1]
		}
	}
	maxVal := 0
	var ans byte
	for i := MAXN - 1; i >= 0; i-- {
		if stats[i] > maxVal {
			maxVal = stats[i]
			ans = byte(i + 'a')
		}
	}
	return ans
}