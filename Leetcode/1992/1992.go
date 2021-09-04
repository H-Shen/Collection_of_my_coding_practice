const STEPS = 2
var dx = [STEPS]int{0,1}
var dy = [STEPS]int{1,0}

var (
	father []int
	Size []int
)
func dsuInit(n int) {
	father = make([]int, n+5)
	Size = make([]int, n+5)
	for i := 0; i < len(father); i++ {
		father[i] = i
	}
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

func minmax(s []int) (int,int) {
	minVal, maxVal := s[0], s[0]
	for i := 1; i < len(s); i++ {
		if minVal > s[i] {
			minVal = s[i]
		}
		if maxVal < s[i] {
			maxVal = s[i]
		}
	}
	return minVal, maxVal
}

func findFarmland(land [][]int) [][]int {
	n := len(land)
	m := len(land[0])
	dsuInit(n*m)
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if land[i][j] == 1 {
				for step := 0; step < STEPS; step++ {
					newI := i + dx[step]
					newJ := j + dy[step]
					if newI >= 0 && newI < n && newJ >= 0 && newJ < m && land[newI][newJ] == 1 {
						merge(i*m+j,newI*m+newJ)
					}
				}
			}
		}
	}
	unmap := make(map[int][]int)
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if land[i][j] == 1 {
				unmap[find(i*m+j)] = append(unmap[find(i*m+j)], i*m+j)
			}
		}
	}
	var ans [][]int
	for _, v := range unmap {
		minVal, maxVal := minmax(v)
		ans = append(ans, []int{minVal/m,minVal%m,maxVal/m,maxVal%m})
	}
	return ans
}