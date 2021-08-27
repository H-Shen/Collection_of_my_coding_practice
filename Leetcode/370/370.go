type BIT struct {
	t1, t2 []int
	N int
}
func lowbit(i int) int {
	return i & (-i)
}
func (bit *BIT) sum(t []int, n int) int {
	a := 0
	for ; n != 0; {
		a += t[n]
		n -= lowbit(n)
	}
	return a
}
func (bit *BIT) SetLength(n int) {
	bit.t1, bit.t2, bit.N = nil, nil, n+1
	bit.t1, bit.t2 = make([]int, bit.N), make([]int, bit.N)
}
// range sum
func (bit *BIT) RangeSum(l, r int) int {
	return (bit.sum(bit.t1,r)*r-bit.sum(bit.t2,r))-(bit.sum(bit.t1,l-1)*(l-1)-bit.sum(bit.t2,l-1))
}
func (bit *BIT) update(t []int, n int, val int) {
	for; n < bit.N; {
		t[n] += val
		n += lowbit(n)
	}
}
// range update
func (bit *BIT) RangeUpdate(l int, r int, val int) {
	bit.update(bit.t1, l, val)
	bit.update(bit.t1, r+1, -val)
	bit.update(bit.t2, l, val*(l-1))
	bit.update(bit.t2, r+1, -val*r)
}

func getModifiedArray(length int, updates [][]int) []int {
	var bit BIT
	var l, r, upd int
	bit.SetLength(length)
	for _, i := range updates {
		l, r, upd = i[0], i[1], i[2]
		l++
		r++
		bit.RangeUpdate(l, r, upd)
	}
	var res = make([]int, length)
	for i := 0; i < length; i++ {
		res[i] = bit.RangeSum(i+1,i+1)
	}
	return res
}