const MAXN int = 1e5+5
var vis = [MAXN]bool{}

func dfs(nums []int, cycleLength int, index int, ans *int) {
	if !vis[nums[index]] {
		vis[nums[index]] = true
		dfs(nums, cycleLength+1, nums[index], ans)
	} else {
		if cycleLength > *ans {
			*ans = cycleLength
		}
	}
}
func arrayNesting(nums []int) int {
	ans := 1
    for i := 0; i < MAXN; i++ {
        vis[i] = false
    }
	for i := 0; i < len(nums); i++ {
		if !vis[i] {
			vis[i] = true
			dfs(nums, 1, i, &ans)
		}
	}
	return ans
}