/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var leaves []*TreeNode
func dfs(root *TreeNode) {
	if root != nil {
		if root.Left != nil {
			dfs(root.Left)
		}
		if root.Right != nil {
			dfs(root.Right)
		}
		if root.Left == nil && root.Right == nil {
			leaves = append(leaves, root)
		}
	}
}
func boundaryOfBinaryTree(root *TreeNode) []int {
	// left
	var left []*TreeNode
	if root.Left != nil {
		node := root.Left
		for {
			left = append(left, node)
			if node.Left != nil {
				node = node.Left
			} else if node.Right != nil {
				node = node.Right
			} else if node.Left == nil && node.Right == nil {
				break
			}
		}
	}
	// leaves
	leaves = nil
	dfs(root)
	// right
	var right []*TreeNode
	if root.Right != nil {
		node := root.Right
		for {
			right = append(right, node)
			if node.Right != nil {
				node = node.Right
			} else if node.Left != nil {
				node = node.Left
			} else if node.Left == nil && node.Right == nil {
				break
			}
		}
	}
	// reverse the right array
    half := len(right)>>1
	for i := 0; i < half; i++ {
		right[i], right[len(right)-i-1] = right[len(right)-i-1], right[i]
	}
	var ans []int
	var s struct{}
	m := make(map[*TreeNode]struct{})
	// add the root
	m[root] = s
	ans = append(ans, root.Val)
	// add the left
	for i := 0; i < len(left); i++ {
		_, ok := m[left[i]]
		if !ok {
			m[left[i]] = s
			ans = append(ans, left[i].Val)
		}
	}
	// add the leaves
	for i := 0; i < len(leaves); i++ {
		_, ok := m[leaves[i]]
		if !ok {
			m[leaves[i]] = s
			ans = append(ans, leaves[i].Val)
		}
	}
	// add the right
	for i := 0; i < len(right); i++ {
		_, ok := m[right[i]]
		if !ok {
			m[right[i]] = s
			ans = append(ans, right[i].Val)
		}
	}
	return ans
}