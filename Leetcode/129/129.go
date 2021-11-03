/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var sum int

func dfs(node *TreeNode, result []int) {
	if node != nil {
		result = append(result, node.Val)
		if node.Left != nil && node.Right != nil {
			dfs(node.Left, result)
			dfs(node.Right, result)
		} else if node.Left != nil && node.Right == nil {
			dfs(node.Left, result)
		} else if node.Left == nil && node.Right != nil {
			dfs(node.Right, result)
		} else {
			if len(result) > 0 {
				runes := make([]rune, len(result))
				for i := 0; i < len(result); i++ {
					runes[i] = rune('0' + result[i])
				}
				temp, err := strconv.Atoi(string(runes))
				if err != nil {
					log.Fatalln(err)
				}
				sum += temp
			}
		}
	}
}

func sumNumbers(root *TreeNode) int {
	sum = 0
    var temp []int
	dfs(root, temp)
	return sum
}