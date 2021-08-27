/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var (
	dp map[*TreeNode]int
	fa map[*TreeNode]*TreeNode
	ans int
)

func dfs1(u *TreeNode, father *TreeNode) {
	if u != nil {
		fa[u] = father
		dfs1((*u).Left, u)
		dfs1((*u).Right, u)
	}
}

func solve(root *TreeNode) int {
	val, ok := dp[root]
	if ok {
		return val
	}
	if fa[root] == nil {
		dp[root] = (*root).Val
	} else {
		var temp = solve(fa[root])
		if temp > (*root).Val {
			dp[root] = temp
		} else {
			dp[root] = (*root).Val
		}
	}
	return dp[root]
}

func dfs2(root *TreeNode) {
	if root != nil {
		if (*root).Val >= solve(root) {
			ans++
		}
		dfs2((*root).Left)
		dfs2((*root).Right)
	}
}

func goodNodes(root *TreeNode) int {
	if root == nil {
		return 0
	}
	dp = nil
	fa = nil
	dp = make(map[*TreeNode]int)
	fa = make(map[*TreeNode]*TreeNode)
	dfs1(root, nil)
	ans = 0
	dfs2(root)
	return ans
}