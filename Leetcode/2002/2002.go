type Node struct {
	pos, length int
}

const N = 13
var bitset [N]bool

func f(val int) {
	for i := 0; i < N; i++ {
		bitset[i] = false
	}
	var index = 0
	for val > 0 {
		if (val & 1) != 0 {
			bitset[index] = true
		}
		index++
		val /= 2
	}
}

func check(s *string, length *int, val int) bool {
	var str []rune
	f(val)
	for i := 0; i < len(*s); i++ {
		if bitset[i] {
			str = append(str, rune((*s)[i]))
		}
	}
	if len(str) == 0 {
		return false
	}
	halfLength := len(str) >> 1
	for i := 0; i < halfLength; i++ {
		if str[i] != str[len(str)-i-1] {
			return false
		}
	}
	*length = len(str)
	return true
}

func maxProduct(s string) int {
	var isPalin []Node
	total := 1<<len(s)
	var length int
	for i := 0; i <= total; i++ {
		if check(&s, &length, i) {
			isPalin = append(isPalin, Node{length: length,pos: i})
		}
	}
    ans := 0
	for i := 0; i < len(isPalin)-1; i++ {
		for j := i+1; j < len(isPalin); j++ {
			if (isPalin[i].pos & isPalin[j].pos) == 0 {
				temp := isPalin[i].length * isPalin[j].length
				if temp > ans {
					ans = temp
				}
			}
		}
	}
	return ans
}