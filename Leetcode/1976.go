type Item struct {
	to int
	cost int64
}
type PriorityQueue []Item
func (pq *PriorityQueue) Len() int {
	return len(*pq)
}
func (pq *PriorityQueue) Less(i, j int) bool {
	if (*pq)[i].cost == (*pq)[j].cost {
		return (*pq)[i].to < (*pq)[j].to
	}
	return (*pq)[i].cost < (*pq)[j].cost
}
func (pq *PriorityQueue) Swap(i, j int) {
	(*pq)[i], (*pq)[j] = (*pq)[j], (*pq)[i]
}
func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(Item))
}
func (pq *PriorityQueue) Pop() interface{} {
	var n = len(*pq)
	var x = (*pq)[n-1]
	*pq = (*pq)[:n-1]
	return x
}
func (pq *PriorityQueue) Empty() bool {
	return (*pq).Len() == 0
}

const (
	MOD int64 = 1e9+7
	INF int64 = 2e18
	N int = 205
)
var (
	dp [N]int64
	dist [N]int64
	AL [N][]Item
)
func dijkstra() {
	dist[0] = 0
	dp[0] = 1
	var pq PriorityQueue
	heap.Init(&pq)
	pq.Push(Item{cost: dist[0], to: 0})
	var dU,w int64
	var u,v int
	for !pq.Empty() {
		var pair = heap.Pop(&pq).(Item)
		dU = pair.cost
		u = pair.to
		if dU != dist[u] {
			continue
		}
		for i := 0; i < len(AL[u]); i++ {
			v = AL[u][i].to
			w = AL[u][i].cost
			if dist[u] + w < dist[v] {
				dist[v] = dist[u] + w
				dp[v] = dp[u]
				heap.Push(&pq, Item{cost: dist[v], to: v})
			} else if dist[u] + w == dist[v] {
				dp[v] = (dp[v] + dp[u]) % MOD
			}
		}
	}
}
func countPaths(n int, roads [][]int) int {
	for i := 0; i < N; i++ {
		dp[i] = 0
	}
	for i := 0; i < N; i++ {
		dist[i] = INF
	}
	for i := 0; i < N; i++ {
		AL[i] = nil
	}
	var u, v int
	var w int64
	for _, road := range roads {
		u = road[0]
		v = road[1]
		w = int64(road[2])
		AL[u] = append(AL[u], Item{to: v, cost: w})
		AL[v] = append(AL[v], Item{to: u, cost: w})
	}
	dijkstra()
	return int(dp[n-1] % MOD)
}