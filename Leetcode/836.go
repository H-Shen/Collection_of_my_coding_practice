func min(x, y int) int {
    if x > y {
        return y
    }
    return x
}
func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}
func isRectangleOverlap(rec1 []int, rec2 []int) bool {
    x1 := max(rec1[0],rec2[0])
    y1 := max(rec1[1],rec2[1])
    x2 := min(rec1[2],rec2[2])
    y2 := min(rec1[3],rec2[3])
    if x1 >= x2 || y1 >= y2 {
        return false
    }
    return true
}