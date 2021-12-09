/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var dp map[*TreeNode]int

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func solve(node *TreeNode) int {
	_, ok := dp[node]
	if ok {
		return dp[node]
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

func dfs(node *TreeNode, sum *int) {
	if node.Left != nil && node.Right != nil {
		*sum += abs(solve(node.Left) - solve(node.Right))
		dfs(node.Left, sum)
		dfs(node.Right, sum)
	} else if node.Left != nil {
		*sum += abs(solve(node.Left))
		dfs(node.Left, sum)
	} else if node.Right != nil {
		*sum += abs(solve(node.Right))
		dfs(node.Right, sum)
	}
}

func findTilt(root *TreeNode) int {
	if root == nil {
		return 0
	}
	dp = make(map[*TreeNode]int)
	sum := 0
	dfs(root, &sum)
	return sum
}