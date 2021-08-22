func beautySum(s string) int {
	const MAXN int = 26
	const LENGTH int = 502
	var pre [LENGTH][MAXN]int
	for i := 1; i <= len(s); i++ {
		for j := 0; j < i; j++ {
			pre[i][s[j] - 'a']++
		}
	}
	var diff [MAXN]int
	var maxFreq, minFreq int
	var sum = 0
	for r := 1; r <= len(s); r++ {
		for l := 1; l <= r; l++ {
			for k := 0; k < MAXN; k++ {
				diff[k] = pre[r][k]-pre[l-1][k]
			}
			maxFreq = 0
			for k := 0; k < MAXN; k++ {
				if maxFreq < diff[k] {
					maxFreq = diff[k]
				}
			}
			if maxFreq > 0 {
				minFreq = LENGTH
				for k := 0; k < MAXN; k++ {
					if diff[k] != 0 && minFreq > diff[k] {
						minFreq = diff[k]
					}
				}
				sum += maxFreq - minFreq
			}
		}
	}
	return sum
}