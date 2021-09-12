type Node struct {
	u, v int
}

func gcd(a, b int) int {
	if a == 0 {
		return b
	} else if b == 0 {
		return a
	}
	return gcd(b, a % b)
}

func interchangeableRectangles(rectangles [][]int) int64 {
	unmap := make(map[Node]int64)
	var node Node
	for i := 0; i < len(rectangles); i++ {
		node.u = rectangles[i][0]
		node.v = rectangles[i][1]
		temp := gcd(node.u, node.v)
		node.u /= temp
		node.v /= temp
		unmap[node]++
	}
	var counter int64 = 0
	for _, v := range unmap {
        counter += (v*(v-1))>>1
	}
	return counter
}