const MAXN int = 26

var (
	bs []bool
	freq [MAXN]int
)

func f(n int, d int) {
	for i := 0; i < d; i++ {
		bs[i] = false
	}
	index := d-1
	for n > 0 {
		if (n & 1) != 0 {
			bs[index] = true
		}
		n >>= 1
		index--
	}
}

func maxLength(arr []string) int {
	ans := 0
	total := 1<<len(arr)
	bs = nil
	bs = make([]bool, len(arr))
	var temp int
	var flag bool
	for i := 1; i < total; i++ {
		f(i, len(arr))
		for j := 0; j < MAXN; j++ {
			freq[j] = 0
		}
		flag = true
		temp = 0
		for j := 0; j < len(arr); j++ {
			if bs[j] {
				temp += len(arr[j])
				for k := 0; k < len(arr[j]); k++ {
					freq[arr[j][k] - 'a']++
					if freq[arr[j][k] - 'a'] > 1 {
						flag = false
						break
					}
				}
			}
			if !flag {
				break
			}
		}
		if flag && temp > ans {
			ans = temp
		}
	}
	return ans
}