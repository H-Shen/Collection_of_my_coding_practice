/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func f(m *map[int]int, k int) bool {
	if (k & 1) == 0 {
		val, ok := (*m)[k >> 1]
		if ok && val > 1 {
			return true
		}
	}
	for i := range *m {
		_, ok := (*m)[k - i]
		if ok && k - i != i {
			return true
		}
	}
	return false
}
func findTarget(root *TreeNode, k int) bool {
	if root == nil {
		return false
	}
	const N int = 1e4+5
	var m map[int]int
	m = make(map[int]int)
	var queue = make(chan *TreeNode, N)
	queue <- root
	for len(queue) > 0 {
		node := <- queue
		m[node.Val]++
		if node.Left != nil {
			queue <- node.Left
		}
		if node.Right != nil {
			queue <- node.Right
		}
	}
	return f(&m, k)
}