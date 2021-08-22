type Bitset []uint64
func (bs *Bitset) Init(n int) {
	*bs = make(Bitset, (n+63)/64)
}
func (bs Bitset) Get(i int) bool {
	return (bs[i/64] & (uint64(1) << (i % 64))) != 0
}
func (bs Bitset) Set(i int, val bool) {
	q, r := i / 64, i % 64
	if val {
		bs[q] |= uint64(1) << r
	} else {
		bs[q] &= ^(uint64(1) << r)
	}
}
func (bs Bitset) Len() int {
	return len(bs)*64
}

func findDifferentBinaryString(nums []string) string {
	const N int = (1<<16)+5
	var bs Bitset
	bs.Init(N)
	for _, num := range nums {
		parseInt, err := strconv.ParseInt(num, 2, 32)
		if err != nil {
            fmt.Println(123)
			os.Exit(1)
		}
		bs.Set(int(parseInt), true)
	}
	var s string
	for i := 0; i < N; i++ {
		if !bs.Get(i) {
			s = strconv.FormatInt(int64(i), 2)
			break
		}
	}
	for len(s) < len(nums) {
		s = "0" + s
	}
	return s
}