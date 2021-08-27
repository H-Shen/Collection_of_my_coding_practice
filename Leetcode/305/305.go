const STEPS int = 4
var (
	Size, father []int
	counter int
	dx = [STEPS]int{0,0,-1,1}
	dy = [STEPS]int{-1,1,0,0}
)

func dsuInit(n int) {
	Size = nil
	father = nil
	Size = make([]int, n+5)
	father = make([]int, n+5)
	for i := 0; i < n+5; i++ {
		Size[i] = 1
	}
	for i := 0; i < n+5; i++ {
		father[i] = i
	}
	counter = 0
}
func find(x int) int {
	if x != father[x] {
		father[x] = find(father[x])
	}
	return father[x]
}
func merge(x, y int){
	x = find(x)
	y = find(y)
	if x == y {
		return
	}
	counter--
	if Size[x] > Size[y] {
		x, y = y, x
	}
	Size[y] += Size[x]
	father[x] = y
}
func numIslands2(m int, n int, positions [][]int) []int {
	dsuInit(m*n)
	var A = make([][]int, m)
	for i := 0; i < m; i++ {
		A[i] = make([]int, n)
	}
	var newI, newJ, i, j int
	var ans = make([]int, len(positions))
	for index, position := range positions {
		i = position[0]
		j = position[1]
		if A[i][j] == 0 {
			A[i][j] = 1
			counter++
			for step := 0; step < STEPS; step++ {
				newI = i +dx[step]
				newJ = j +dy[step]
				if newI >= 0 && newI < m && newJ >= 0 && newJ < n && A[newI][newJ] == 1 {
					merge(i*n+j, newI*n+newJ)
				}
			}
		}
		ans[index] = counter
	}
	return ans
}