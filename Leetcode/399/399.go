const (
	INF = 100000000.0
)

func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
	nodes := make(map[string]int)
	id := 0
	for i := 0; i < len(equations); i++ {
		if _, ok := nodes[equations[i][0]]; !ok {
			nodes[equations[i][0]] = id
			id++
		}
		if _, ok := nodes[equations[i][1]]; !ok {
			nodes[equations[i][1]] = id
			id++
		}
	}
	for i := 0; i < len(queries); i++ {
		if _, ok := nodes[queries[i][0]]; !ok {
			nodes[queries[i][0]] = id
			id++
		}
		if _, ok := nodes[queries[i][1]]; !ok {
			nodes[queries[i][1]] = id
			id++
		}
	}
	am := make([][]float64, id)
	for i := 0; i < id; i++ {
		am[i] = make([]float64, id)
		for j := 0; j < id; j++ {
			am[i][j] = INF
		}
	}
	for i := 0; i < len(equations); i++ {
		u := nodes[equations[i][0]]
		v := nodes[equations[i][1]]
		am[u][v] = values[i]
		am[v][u] = 1.0 / values[i]
	}
	// floyd
	var temp float64
	for k := 0; k < id; k++ {
		for i := 0; i < id; i++ {
			for j := 0; j < id; j++ {
				if am[i][k] < INF && am[k][j] < INF {
					temp = am[i][k] * am[k][j]
					if temp < am[i][j] {
						am[i][j] = temp
					}
				}
			}
		}
	}
	answer := make([]float64, len(queries))
    for i := 0; i < len(queries); i++ {
		u := nodes[queries[i][0]]
		v := nodes[queries[i][1]]
        if am[u][v] == INF {
            answer[i] = -1.0
        } else {
		    answer[i] = am[u][v]
        }
	}
	return answer
}