var (
	father []int
	Size []int
	cc int
)
func dsuInit(n int) {
	father = nil
	Size = nil
	father = make([]int, n+5)
	Size = make([]int, n+5)
	for i := 0; i < n+5; i++ {
		father[i] = i
	}
	for i := 0; i < n+5; i++ {
		Size[i] = 1
	}
	cc = n
}
func find(x int) int {
	if x != father[x] {
		father[x] = find(father[x])
	}
	return father[x]
}
func merge(x, y int) {
	x = find(x)
	y = find(y)
	if x == y {
		return
	}
	cc--
	if Size[x] > Size[y] {
		x, y = y, x
	}
	Size[y] += Size[x]
	father[x] = y
}

func validTree(n int, edges [][]int) bool {
	if len(edges) != n-1 {
		return false
	}
	dsuInit(n)
	for i := 0; i < len(edges); i++ {
		merge(edges[i][0], edges[i][1])
	}
	return cc == 1
}