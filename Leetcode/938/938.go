/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func dfs(node *TreeNode, low int, high int, sum *int) {
	if node != nil {
		if node.Val < low {
			dfs(node.Right, low, high, sum)
		} else if node.Val > high {
			dfs(node.Left, low, high, sum)
		} else {
			*sum += node.Val
			dfs(node.Left, low, high, sum)
			dfs(node.Right, low, high, sum)
		}
	}
}

func rangeSumBST(root *TreeNode, low int, high int) int {
	sum := 0
	dfs(root, low, high, &sum)
	return sum
}