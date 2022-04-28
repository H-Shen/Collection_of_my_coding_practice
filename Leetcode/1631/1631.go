const (
	STEPS = 4
)

var (
	dx = []int{-1, 1, 0, 0}
	dy = []int{0, 0, -1, 1}
)

type Node struct {
	x   int
	y   int
	gap int
}

func NewNode(x int, y int, gap int) Node {
	return Node{x: x, y: y, gap: gap}
}

type PriorityQueue []Node

func (pq *PriorityQueue) Len() int {
	return len(*pq)
}

func (pq *PriorityQueue) Less(i, j int) bool {
	lGap := (*pq)[i].gap
	rGap := (*pq)[j].gap
	return lGap < rGap
}

func (pq *PriorityQueue) Swap(i, j int) {
	(*pq)[i], (*pq)[j] = (*pq)[j], (*pq)[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(Node))
}

func (pq *PriorityQueue) Pop() interface{} {
	n := len(*pq)
	x := (*pq)[n-1]
	*pq = (*pq)[:(n - 1)]
	return x
}

func (pq *PriorityQueue) Empty() bool {
	return len(*pq) == 0
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func minimumEffortPath(heights [][]int) int {
	// bfs
	n := len(heights)
	m := len(heights[0])
	vis := make([][]bool, n)
	for i := 0; i < n; i++ {
		vis[i] = make([]bool, m)
	}
	var myPq PriorityQueue
	heap.Init(&myPq)
	heap.Push(&myPq, NewNode(0,0,0))
	maxDiff := -1
	var newX int
	var newY int
	for !myPq.Empty() {
		node := heap.Pop(&myPq).(Node)
		if vis[node.x][node.y] {
			continue
		}
		vis[node.x][node.y] = true
		if node.gap > maxDiff {
			maxDiff = node.gap
		}
		if node.x == n-1 && node.y == m-1 {
			break
		}
		for i := 0; i < STEPS; i++ {
			newX = node.x + dx[i]
			newY = node.y + dy[i]
			if newX >= 0 && newX < n && newY >= 0 && newY < m {
				heap.Push(&myPq, NewNode(newX, newY, abs(heights[newX][newY]-heights[node.x][node.y])))
			}
		}
	}
	return maxDiff
}