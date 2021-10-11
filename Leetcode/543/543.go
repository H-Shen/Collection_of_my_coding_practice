/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var (
	d1 []int
	d2 []int
	AL [][]int
	node2id map[*TreeNode]int
	id int
)

func dfs(root *TreeNode) {
	if root != nil {
		node2id[root] = id
		id++
		dfs(root.Left)
		dfs(root.Right)
	}
}
func dfs2(root *TreeNode) {
	if root != nil {
		u := node2id[root]
		if root.Left != nil {
			v := node2id[root.Left]
			AL[u] = append(AL[u], v)
			AL[v] = append(AL[v], u)
		}
		if root.Right != nil {
			v := node2id[root.Right]
			AL[u] = append(AL[u], v)
			AL[v] = append(AL[v], u)
		}
		dfs2(root.Left)
		dfs2(root.Right)
	}
}
func dfs3(u, fa int) {
	d1[u] = 0
	d2[u] = 0
	for _, v := range AL[u] {
		if v == fa {
			continue
		}
		dfs3(v, u)
		temp := d1[v] + 1
		if temp > d1[u] {
			d2[u] = d1[u]
			d1[u] = temp
		} else if temp > d2[u] {
			d2[u] = temp
		}
	}
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func diameterOfBinaryTree(root *TreeNode) int {
	id = 0
    node2id = make(map[*TreeNode]int)
	dfs(root)
	AL = make([][]int, id)
	dfs2(root)
	d1 = make([]int, id)
	d2 = make([]int, id)
	dfs3(0, -1)
	ans := 0
	for i := 0; i < id; i++ {
		ans = max(ans, d1[i] + d2[i])
	}
	return ans
}