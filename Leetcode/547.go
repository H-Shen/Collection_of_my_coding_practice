const N int = 205

var (
	father [N]int
	Size[N]int
	ans int
)

func dsuInit() {
	for i := 0; i < N; i++ {
		father[i] = i
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
	ans--
	if Size[x] > Size[y] {
		x,y = y,x
	}
	Size[y] += Size[x]
	father[x] = y
}

func findCircleNum(isConnected [][]int) int {
	dsuInit()
	n := len(isConnected)
	ans = n
	for i := 1; i <= n ; i++ {
		for j := 1; j <= n; j++ {
			if isConnected[i-1][j-1] == 1 {
				merge(i, j)
			}
		}
	}
	return ans
}