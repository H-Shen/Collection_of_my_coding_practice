const MAXN = 1002

func min(a ... int) int {
	ans := math.MaxInt32
	for _, i := range a {
		if i < ans {
			ans = i
		}
	}
	return ans
}

func max(a ... int) int {
	ans := math.MinInt32
	for _, i := range a {
		if i > ans {
			ans = i
		}
	}
	return ans
}

type DetectSquares struct {
	vis [MAXN][MAXN]int
	counter, minX, maxX, minY, maxY int
}

func Constructor() DetectSquares {
	obj := DetectSquares{
		minX: math.MaxInt32,
		maxX: math.MinInt32,
		minY: math.MaxInt32,
		maxY: math.MinInt32,
	}
	return obj
}

func (this *DetectSquares) Add(point []int)  {
	this.vis[point[0]][point[1]]++
	this.counter++
	this.minX = min(this.minX, point[0])
	this.maxX = max(this.maxX, point[0])
	this.minY = min(this.minY, point[1])
	this.maxY = max(this.maxY, point[1])
}

func (this *DetectSquares) Count(point []int) int {
	if this.counter < 3 {
		return 0
	}
	counter := 0
	x, y, r := point[0], point[1], 1
	for {
		if x-r < this.minX || y-r < this.minY {
			break
		}
		counter += this.vis[x-r][y] * this.vis[x-r][y-r] * this.vis[x][y-r]
		r++
	}
	r = 1
	for {
		if x-r < this.minX || y+r > this.maxY {
			break
		}
		counter += this.vis[x-r][y] * this.vis[x-r][y+r] * this.vis[x][y+r]
		r++
	}
	r = 1
	for {
		if x+r > this.maxX || y+r > this.maxY {
			break
		}
		counter += this.vis[x][y+r] * this.vis[x+r][y+r] * this.vis[x+r][y]
		r++
	}
	r = 1
	for {
		if x+r > this.maxX || y-r < this.minY {
			break
		}
		counter += this.vis[x+r][y] * this.vis[x+r][y-r] * this.vis[x][y-r]
		r++
	}
	return counter
}


/**
 * Your DetectSquares object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(point);
 * param_2 := obj.Count(point);
 */