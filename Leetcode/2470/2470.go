type ST struct {
	Log2 []int64
	spt  [][]big.Int
	n    int
	logn int
}

func GCD(p, q *big.Int) *big.Int {
	return new(big.Int).GCD(big.NewInt(1), big.NewInt(1), p, q)
}

func LCM(a *big.Int, b *big.Int) *big.Int {
	return new(big.Int).Div(new(big.Int).Mul(a, b), GCD(a, b))
}

func NewST(n int) *ST {
	st := ST{n: n}
	st.Log2 = make([]int64, n+5)
	st.Log2[0] = 0
	st.Log2[1] = 0
	st.Log2[2] = 1
	for i := 3; i < n+5; i++ {
		st.Log2[i] = st.Log2[i>>1] + 1
	}
	st.logn = int(st.Log2[n] + 2)
	st.spt = make([][]big.Int, n+5)
	for i := 0; i < n+5; i++ {
		st.spt[i] = make([]big.Int, st.logn)
	}
	return &st
}

func initST(st *ST) {
	for j := 1; j <= st.logn; j++ {
		for i := 1; i+(1<<j)-1 <= st.n; i++ {
			st.spt[i][j] = *LCM(&st.spt[i][j-1], &st.spt[i+(1<<(j-1))][j-1])
		}
	}
}

func query(st *ST, l int, r int) *big.Int {
	pos := st.Log2[r-l+1]
    return LCM(&st.spt[l][pos], &st.spt[r-(1<<pos)+1][pos])
}

func subarrayLCM(nums []int, k int) int {
	n := len(nums)
	st := NewST(n)
	for i := 1; i <= n; i++ {
		st.spt[i][0] = *big.NewInt(int64(nums[i-1]))
	}
	initST(st)
	ans := 0
	bigIntK := big.NewInt(int64(k))
	for l := 0; l < n; l++ {
		if k%nums[l] != 0 {
			continue
		}
		for r := l; r < n; r++ {
			if k%nums[r] != 0 {
				break
			}
            res := query(st, l+1, r+1)
			if res.Cmp(bigIntK) == 0 {
				ans++
			}
		}
	}
	return ans
}