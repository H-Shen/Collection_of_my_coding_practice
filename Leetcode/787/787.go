func findCheapestPrice(n int, flights [][]int, src int, dst int, k int) int {
    const INF int = 0x3f3f3f3f
    var dist = make([]int, n)
    for i := 0; i < n; i++ {
        dist[i] = INF
    }
    dist[src] = 0
    var u, v, w int
    var last = make([]int, n)
    for i := 0; i < k+1; i++ {
        copy(last, dist)
        for _, j := range flights {
            u, v, w = j[0], j[1], j[2]
            if last[u] + w < dist[v] {
                dist[v] = last[u] + w
            }
        }
    }
    if dist[dst] >= INF {
        return -1
    }
    return dist[dst]
}