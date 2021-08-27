const STEPS int = 4
var (
	Size, father []int
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
	if Size[x] > Size[y] {
		x, y = y, x
	}
	Size[y] += Size[x]
	father[x] = y
}
func largestIsland(grid [][]int) int {
    var n = len(grid)
    dsuInit(n*n)
    var newI, newJ int
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            if grid[i][j] == 1 {
                for step := 0; step < STEPS; step++ {
                    newI = i+dx[step]
                    newJ = j+dy[step]
                    if newI >= 0 && newI < n && newJ >= 0 && newJ < n && grid[newI][newJ] == 1 {
                        merge(i*n+j,newI*n+newJ)
                    }
                }
            }
        }
    }
    var maxSize = 0
    var temp int
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            if grid[i][j] == 1 {
                temp = Size[find(i*n+j)]
                if temp > maxSize {
                    maxSize = temp
                }
            }
        }
    }
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            if grid[i][j] == 0 {
                temp = 1
                var unmap map[int]int
                unmap = make(map[int]int)
                for step := 0; step < STEPS; step++ {
                    newI = i+dx[step]
                    newJ = j+dy[step]
                    if newI >= 0 && newI < n && newJ >= 0 && newJ < n && grid[newI][newJ] == 1 {
                        unmap[find(newI*n+newJ)]++
                    }
                }
                for k, _ := range unmap {
                    temp += Size[find(k)]
                }
                if temp > maxSize {
                    maxSize = temp
                }
            }
        }
    }
    return maxSize
}