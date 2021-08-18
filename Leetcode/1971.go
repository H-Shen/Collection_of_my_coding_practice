const N int = 2*1e5+5
var (
	father [N]int
	Size [N]int
)

func dsuInit(n int) {
	for i := 0; i < n; i++ {
		father[i] = i
		Size[i] = 1
	}
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
	if Size[x] > Size[y] {
		x, y = y, x
	}
	Size[y] += Size[x]
	father[x] = y
}

func validPath(n int, edges [][]int, start int, end int) bool {
	dsuInit(n)
	for _, edge := range edges {
		merge(edge[0], edge[1])
	}
	return find(start) == find(end)
}