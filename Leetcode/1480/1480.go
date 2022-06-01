func runningSum(nums []int) []int {
    pre := make([]int, len(nums))
    pre[0] = nums[0]
    for i := 1; i < len(nums); i++ {
        pre[i] = pre[i-1] + nums[i]
    }
    return pre
}