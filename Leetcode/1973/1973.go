/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var dp map[*TreeNode]int64

func solve(node *TreeNode) int64 {
	val, ok := dp[node]
	if ok {
		return val
	}
    dp[node] = int64((*node).Val)
	if (*node).Left != nil {
		dp[node] += solve((*node).Left)
	}
	if (*node).Right != nil {
		dp[node] += solve((*node).Right)
	}
	return dp[node]
}

func equalToDescendants(root *TreeNode) int {
	if root == nil {
		return 0
	}
	const MAXN int = 1e5+5
	dp = nil
	dp = make(map[*TreeNode]int64)
	queue := make(chan *TreeNode, MAXN)
	// bfs
	queue <- root
	ans := 0
	for ; len(queue) > 0; {
		node := <- queue
		if solve(node) == int64((*node).Val) << 1 {
			ans++
		}
		if (*node).Left != nil {
			queue <- (*node).Left
		}
		if (*node).Right != nil {
			queue <- (*node).Right
		}
	}
	close(queue)
	return ans
}