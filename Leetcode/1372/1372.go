/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var (
	father map[*TreeNode]*TreeNode
	dp map[*TreeNode]int
)
func dfs(node *TreeNode, fa *TreeNode) {
	if node != nil {
		father[node] = fa
		if node.Left != nil {
			dfs(node.Left, node)
		}
		if node.Right != nil {
			dfs(node.Right, node)
		}
	}
}
func solve(node *TreeNode) int {
	val, ok := dp[node]
	if ok {
		return val
	}
	if father[node] == nil {
		dp[node] = 0
	} else if node == father[node].Left {
		if father[father[node]] == nil {
			dp[node] = 1
		} else if father[node] == father[father[node]].Left {
			dp[node] = 1
		} else {
			dp[node] = dp[father[node]] + 1
		}
	} else {
		if father[father[node]] == nil {
			dp[node] = 1
		} else if father[node] == father[father[node]].Right {
			dp[node] = 1
		} else {
			dp[node] = dp[father[node]] + 1
		}
	}
	return dp[node]
}
func dfs2(node *TreeNode, ans *int) {
	if node != nil {
		temp := solve(node)
		if temp > *ans {
			*ans = temp
		}
		dfs2(node.Left, ans)
		dfs2(node.Right, ans)
	}
}
func longestZigZag(root *TreeNode) int {
	father = nil
	father = make(map[*TreeNode]*TreeNode)
	dfs(root, nil)
	dp = nil
	dp = make(map[*TreeNode]int)
	ans := 0
	dfs2(root, &ans)
	return ans
}