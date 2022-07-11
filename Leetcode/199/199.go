/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func getHeight(node *TreeNode) int {
	if node == nil {
		return 0
	}
	return 1 + max(getHeight(node.Left), getHeight(node.Right))
}

type Pair struct {
	Node *TreeNode
	Level int
}

func rightSideView(root *TreeNode) []int {
	var result []int
	if root == nil {
		return result
	}
	// get height
	height := getHeight(root)
	levels := make([][]int, height)
	// bfs
	var queue []Pair
	queue = append(queue, Pair{
		Node:   root,
		Level: 0,
	})
	for len(queue) > 0 {
		front := queue[0]
		queue = queue[1:]
		levels[front.Level] = append(levels[front.Level], front.Node.Val)
		if front.Node.Left != nil {
			queue = append(queue, Pair{
				Node: front.Node.Left,
				Level: front.Level+1,
			})
		}
		if front.Node.Right != nil {
			queue = append(queue, Pair{
				Node: front.Node.Right,
				Level: front.Level+1,
			})
		}
	}
	for i := 0; i < len(levels); i++ {
		result = append(result, levels[i][len(levels[i])-1])
	}
	return result
}