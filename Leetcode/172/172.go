func trailingZeroes(n int) int {
    ans := 0
    temp := 0
    for; n >= 5; {
        temp = n / 5
        ans += temp
        n = temp
    }
    return ans
}