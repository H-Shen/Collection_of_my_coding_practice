var (
	father []int
	Size   []int
)

func initDsu(n int) {
	father = nil
	Size = nil
	father = make([]int, n+5)
	for i := 0; i < len(father); i++ {
		father[i] = i
	}
	Size = make([]int, n+5)
	for i := 0; i < len(Size); i++ {
		Size[i] = 1
	}
}

func find(x int) int {
	if father[x] != x {
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

func isSameGroup(x, y int) bool {
	return find(x) == find(y)
}

type Edge struct {
	u int
	v int
	w int
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func minCostConnectPoints(points [][]int) int {
	n := len(points)
	initDsu(n)
	var edges []Edge
	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			edges = append(edges, Edge{
				u: i,
				v: j,
				w: abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]),
			})
		}
	}
	sort.Slice(edges, func(i, j int) bool {
		return edges[i].w < edges[j].w
	})
	cost := 0
	for i := 0; i < len(edges); i++ {
		if !isSameGroup(edges[i].u, edges[i].v) {
			merge(edges[i].u, edges[i].v)
			cost += edges[i].w
		}
	}
	return cost
}