/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var vec []*TreeNode

func dfs(root *TreeNode, curDepth int, depth int)  {
	if root != nil {
		if curDepth == depth - 1 {
			vec = append(vec, root)
		} else if curDepth > depth - 1 {
			return
		}
		dfs(root.Left, curDepth+1, depth)
		dfs(root.Right, curDepth+1, depth)
	}
}

func addOneRow(root *TreeNode, val int, depth int) *TreeNode {
	if depth == 1 {
		node := new(TreeNode)
		node.Val = val
		node.Left = root
		return node
	}
	vec = nil
	dfs(root, 1, depth)
	for i := 0; i < len(vec); i++ {
		leftNode := new(TreeNode)
		leftNode.Val = val
		if vec[i].Left != nil {
			leftNode.Left = vec[i].Left
			vec[i].Left = leftNode
		} else {
			vec[i].Left = leftNode
		}
		rightNode := new(TreeNode)
		rightNode.Val = val
		if vec[i].Right != nil {
			rightNode.Right = vec[i].Right
			vec[i].Right = rightNode
		} else {
			vec[i].Right = rightNode
		}
	}
	return root
}