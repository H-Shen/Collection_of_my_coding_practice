/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func dfs(node *TreeNode, A *[]int) {
	if node != nil {
		dfs(node.Left, A)
		*A = append(*A, node.Val)
		dfs(node.Right, A)
	}
}
func getAllElements(root1 *TreeNode, root2 *TreeNode) []int {
	var a []int
	var b []int
	dfs(root1, &a)
	dfs(root2, &b)
	var result []int
	i, j := 0, 0
	for ; i < len(a) && j < len(b); {
		if a[i] < b[j] {
			result = append(result, a[i])
			i++
		} else if a[i] == b[j] {
			result = append(result, a[i])
			result = append(result, b[j])
			i++
			j++
		} else {
			result = append(result, b[j])
			j++
		}
	}
	for ; i < len(a); i++ {
		result = append(result, a[i])
	}
	for ; j < len(b); j++ {
		result = append(result, b[j])
	}
	return result
}