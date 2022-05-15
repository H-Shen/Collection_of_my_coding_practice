/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var (
	height int
	sum int
)
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func getHeight(root *TreeNode) int {
	if root != nil {
		return 1 + max(getHeight(root.Left), getHeight(root.Right))
	}
	return 0
}
func dfs(root *TreeNode, currHeight int) {
	if height == currHeight {
		sum += root.Val
	}
	if root.Left != nil {
		dfs(root.Left, currHeight+1)
	}
	if root.Right != nil {
		dfs(root.Right, currHeight+1)
	}
}
func deepestLeavesSum(root *TreeNode) int {
	height = getHeight(root)
	sum = 0
	dfs(root, 1)
	return sum
}