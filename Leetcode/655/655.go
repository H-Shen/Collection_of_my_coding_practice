/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type Node struct {
	treeNode *TreeNode
	r, c int
}
var height int
func dfs(root *TreeNode, curHeight int) {
	if root != nil {
		if curHeight > height {
			height = curHeight
		}
		dfs(root.Left, curHeight+1)
		dfs(root.Right, curHeight+1)
	}
}
func printTree(root *TreeNode) [][]string {
	height = 0
	dfs(root, 0)
	rows := height+1
	cols := (1<<(height+1))-1
	ans := make([][]string, rows)
	for i := 0; i < rows; i++ {
		ans[i] = make([]string, cols)
	}
	const N int = (1<<10)+5
	queue := make(chan Node, N)
	queue <- Node{root,0,(cols-1)>>1}
	var newCol int
	for len(queue) > 0 {
		var node = <- queue
		ans[node.r][node.c] = strconv.Itoa(node.treeNode.Val)
		if node.treeNode.Left != nil {
			newCol = node.c - (1<<(height-node.r-1))
			queue <- Node{node.treeNode.Left, node.r+1, newCol}
		}
		if node.treeNode.Right != nil {
			newCol = node.c + (1<<(height-node.r-1))
			queue <- Node{node.treeNode.Right, node.r+1, newCol}
		}
	}
	return ans
}