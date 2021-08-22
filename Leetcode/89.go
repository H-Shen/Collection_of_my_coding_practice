func grayCode(n int) []int {
    ans := make([]int, (1<<n))
    for i := 0; i < len(ans); i++ {
        ans[i] = i^(i>>1)
    }
    return ans
}