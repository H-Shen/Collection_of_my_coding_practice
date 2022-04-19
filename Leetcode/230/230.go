/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func dfs(root *TreeNode, k *int, haveAns *bool, answer *int) {
	if *haveAns {
		return
	}
	if root != nil {
		dfs(root.Left, k, haveAns, answer)
        (*k)--
		if *k == 0 {
			*answer = root.Val
			*haveAns = true
			return
		}
		dfs(root.Right, k, haveAns, answer)
	}
}

func kthSmallest(root *TreeNode, k int) int {
    haveAns := false
    var answer int
	dfs(root, &k, &haveAns, &answer)
	return answer
}