/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var dp map[*TreeNode]int

func solve(node *TreeNode) int {
	val, ok := dp[node]
	if ok {
		return val
	}
	dp[node] = node.Val
	if node.Left != nil {
		dp[node] += solve(node.Left)
	}
	if node.Right != nil {
		dp[node] += solve(node.Right)
	}
	return dp[node]
}

func dfs(node *TreeNode) {
	if node != nil {
		if node.Left != nil && solve(node.Left) == 0 {
			node.Left = nil
		}
		dfs(node.Left)
		if node.Right != nil && solve(node.Right) == 0 {
			node.Right = nil
		}
		dfs(node.Right)
	}
}

func pruneTree(root *TreeNode) *TreeNode {
	dp = nil
    dp = make(map[*TreeNode]int)
	if solve(root) == 0 {
		return nil
	}
	const MAXN = 205
	queue := make(chan *TreeNode, MAXN)
	queue <- root
	var vec []*TreeNode
	for len(queue) > 0 {
		node := <- queue
		vec = append(vec, node)
		if node.Left != nil {
			queue <- node.Left
		}
		if node.Right != nil {
			queue <- node.Right
		}
	}
    dfs(root)
	return root
}