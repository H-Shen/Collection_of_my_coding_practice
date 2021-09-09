/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * type BinaryMatrix struct {
 *     Get func(int, int) int
 *     Dimensions func() []int
 * }
 */

func leftMostColumnWithOne(binaryMatrix BinaryMatrix) int {
	const INF = 0x3f3f3f3f
	p := binaryMatrix.Dimensions()
	row := p[0]
	col := p[1]
	leftColIndex := INF
	var l, r, mid, ans int
	for i := 0; i < row; i++ {
		l = 0
		if leftColIndex == INF {
			r = col - 1
		} else {
			r = leftColIndex
		}
		ans = INF
		for l <= r {
			mid = l + ((r-l)>>1)
			if binaryMatrix.Get(i, mid) == 1 {
				if mid < ans {
					ans = mid
				}
				r = mid - 1
			} else {
				l = mid + 1
			}
		}
		if leftColIndex > ans {
			leftColIndex = ans
		}
	}
	if leftColIndex == INF {
		return -1
	}
	return leftColIndex
}