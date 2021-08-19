/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
const MOD int64 = 1e9 + 7
var (
	dp map[*TreeNode]int
	sum int
    ans int64
)
func solve(root *TreeNode) int {
	val, ok := dp[root]
	if ok {
		return val
	}
	dp[root] = (*root).Val
	if (*root).Left != nil {
		dp[root] += solve((*root).Left)
	}
	if (*root).Right != nil {
		dp[root] += solve((*root).Right)
	}
	return dp[root]
}
func dfs1(root *TreeNode) {
	if root != nil {
        sum += (*root).Val
		dfs1((*root).Left)
		dfs1((*root).Right)
	}
}
func dfs2(root *TreeNode) {
	if root != nil {
		var leftSum = solve(root)
        var rightSum = sum - leftSum
        var temp = int64(leftSum) * int64(rightSum)
        if temp > ans {
            ans = temp
        }
		dfs2((*root).Left)
		dfs2((*root).Right)
	}
}
func maxProduct(root *TreeNode) int {
	dp = nil
	dp = make(map[*TreeNode]int)
	ans = math.MinInt32
	sum = 0
	dfs1(root)
	dfs2(root)
    return int(ans % MOD)
}