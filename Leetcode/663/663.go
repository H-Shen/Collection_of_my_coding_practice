/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
const MAXN = 1e4 + 5
var dp map[*TreeNode]int

func solve(root *TreeNode) int {
	val, ok := dp[root]
	if ok {
		return val
	}
	dp[root] = root.Val
	if root.Left != nil {
		dp[root] += solve(root.Left)
	}
	if root.Right != nil {
		dp[root] += solve(root.Right)
	}
	return dp[root]
}

func checkEqualTree(root *TreeNode) bool {
	dp = nil
	dp = make(map[*TreeNode]int)
	// bfs
	queue := make(chan *TreeNode, MAXN)
	sumOfTree := solve(root)
	queue <- root
	for len(queue) > 0 {
		node := <- queue
		if node != root && sumOfTree == solve(node)<<1 {
			return true
		}
		if node.Left != nil {
			queue <- node.Left
		}
		if node.Right != nil {
			queue <- node.Right
		}
	}
	return false
}