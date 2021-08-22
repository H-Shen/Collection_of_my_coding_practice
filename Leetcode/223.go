func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}
func min(x, y int) int {
    if x > y {
        return y
    }
    return x
}
func computeArea(ax1 int, ay1 int, ax2 int, ay2 int, bx1 int, by1 int, bx2 int, by2 int) int {
    x1 := int64(max(ax1, bx1))
    y1 := int64(max(ay1, by1))
    x2 := int64(min(ax2, bx2))
    y2 := int64(min(ay2, by2))
    var overlapped int64
    if x1 > x2 || y1 > y2 {
        overlapped = 0
    } else {
        overlapped = (x2-x1)*(y2-y1)
    }
    return int(int64((ax2-ax1)*(ay2-ay1)) + int64((bx2-bx1)*(by2-by1)) - overlapped)
}