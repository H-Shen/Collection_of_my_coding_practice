type Pair struct {
	ch rune
	freq int
}
type stack []Pair

func (s *stack) Empty() bool {
	return len(*s) == 0
}
func (s *stack) Top() *Pair {
	if (*s).Empty() {
		panic("empty stack!")
	}
	return &(*s)[len(*s)-1]
}
func (s *stack) Pop() {
	if !(*s).Empty() {
		*s = (*s)[:len(*s)-1]
	}
}
func (s *stack) Push(x Pair) {
	*s = append(*s, x)
}

func removeDuplicates(s string, k int) string {
	var sta stack
	for _, ch := range s {
		if sta.Empty() {
			sta.Push(Pair{ch, 1})
		} else if sta.Top().ch != ch {
			sta.Push(Pair{ch, 1})
		} else {
			sta.Top().freq++
			if sta.Top().freq >= k {
				sta.Top().freq -= k
				if sta.Top().freq == 0 {
					sta.Pop()
				}
			}
		}
	}
	var sb strings.Builder
	for !sta.Empty() {
		for i := 0; i < sta.Top().freq; i++ {
			sb.WriteRune(sta.Top().ch)
		}
		sta.Pop()
	}
	var temp = []rune(sb.String())
	for i := 0; i < len(temp)/2; i++ {
		temp[i], temp[len(temp)-i-1] = temp[len(temp)-i-1], temp[i]
	}
	return string(temp)
}