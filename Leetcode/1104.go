func f(level int, powerOfTwo []int) int {
	if level == 1 {
		return 1
	}
	return powerOfTwo[level-1] + powerOfTwo[level] - 1
}
func pathInZigZagTree(label int) []int {
	const MAXN int = 1e6 + 5
	var powerOfTwo []int
	powerOfTwo = append(powerOfTwo, 1)
	for ; powerOfTwo[len(powerOfTwo)-1] <= MAXN; {
		powerOfTwo = append(powerOfTwo, powerOfTwo[len(powerOfTwo)-1]<<1)
	}
	var ans []int
	var level = -1
	for i := 1; ; i++ {
		if powerOfTwo[i-1] <= label && label <= powerOfTwo[i]-1 {
			level = i
			break
		}
	}
	for {
		ans = append(ans, label)
		if label == 1 {
			break
		}
		if level&1 != 0 {
			label = f(level-1, powerOfTwo) - (label >> 1)
		} else {
			label = (f(level, powerOfTwo) - label) >> 1
		}
		level--
	}
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return ans
}