/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
const MAXN = 105
var depth [MAXN]int
var parent [MAXN]int

func dfs1(root *TreeNode, d int) {
	if root != nil {
		depth[root.Val] = d
		dfs1(root.Left, d+1)
		dfs1(root.Right, d+1)
	}
}

func dfs2(u, fa *TreeNode) {
	if u != nil {
		if fa != nil {
			parent[u.Val] = fa.Val
		}
        dfs2(u.Left, u)
        dfs2(u.Right, u)
	}
}

func isCousins(root *TreeNode, x int, y int) bool {
	dfs1(root, 0)
	parent[root.Val] = -1
	dfs2(root, nil)
	return depth[x] == depth[y] && parent[x] != parent[y]
}