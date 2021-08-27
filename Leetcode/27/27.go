func removeElement(nums []int, val int) int {
    var ans = 0
    for i := 0; i < len(nums); i++ {
        if nums[i] != val {
            if ans != i {
                nums[ans] = nums[i]
            }
            ans++
        }
    }
    return ans
}