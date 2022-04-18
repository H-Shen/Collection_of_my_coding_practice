/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var nodes []*TreeNode

func dfs(node *TreeNode) {
	if node != nil {
		dfs(node.Left)
		nodes = append(nodes, node)
		dfs(node.Right)
	}
}
func increasingBST(root *TreeNode) *TreeNode {
	nodes = nil
	dfs(root)
	for i := 0; i < len(nodes)-1; i++ {
		nodes[i].Left = nil
		nodes[i].Right = nodes[i+1]
	}
	nodes[len(nodes)-1].Left = nil
	nodes[len(nodes)-1].Right = nil
	return nodes[0]
}
