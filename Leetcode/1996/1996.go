type Pair struct {
	a, b int
}
func numberOfWeakCharacters(properties [][]int) int {
	A := make([]Pair, len(properties))
	for i := 0; i < len(properties); i++ {
		A[i].a = properties[i][0]
		A[i].b = properties[i][1]
	}
	sort.Slice(A, func(i, j int) bool {
		return A[i].a < A[j].a
	})
	maxFromRight := make([]int, len(A))
	maxFromRight[len(A)-1] = A[len(A)-1].b
	for i := len(A)-2; i >= 0; i-- {
		if maxFromRight[i+1] > A[i].b {
			maxFromRight[i] = maxFromRight[i+1]
		} else {
			maxFromRight[i] = A[i].b
		}
	}
	counter := 0
	temp := Pair{0, -1}
	for i := 0; i < len(A); i++ {
		temp.a = A[i].a
		pos := sort.Search(len(A), func(i int) bool {
			return A[i].a > temp.a
		})
		if pos != len(A) && A[i].b < maxFromRight[pos] {
			counter++
		}
	}
	return counter
}