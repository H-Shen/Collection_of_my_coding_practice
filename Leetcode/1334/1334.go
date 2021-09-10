func findTheCity(n int, edges [][]int, distanceThreshold int) int {
	const INF = 0x3f3f3f3f
	am := make([][]int, n)
	for i := 0; i < n; i++ {
		am[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			am[i][j] = INF
		}
	}
	for i := 0; i < n; i++ {
		am[i][i] = 0
	}
	var u, v, w int
	for i := 0; i < len(edges); i++ {
		u = edges[i][0]
		v = edges[i][1]
		w = edges[i][2]
		am[u][v] = w
		am[v][u] = w
	}
	for k := 0; k < n; k++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if am[i][j] > am[i][k] + am[k][j] {
					am[i][j] = am[i][k] + am[k][j]
				}
			}
		}
	}
	stats := make([]int, n)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i != j && am[i][j] <= distanceThreshold {
				stats[i]++
			}
		}
	}
	minVal := INF
	for i := 0; i < n; i++ {
		if stats[i] < minVal {
			minVal = stats[i]
		}
	}
	for i := n-1; i >= 0; i-- {
		if stats[i] == minVal {
			return i
		}
	}
	return -1
}