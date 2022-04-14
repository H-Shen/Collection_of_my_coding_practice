/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var answer *TreeNode

func dfs(root *TreeNode, val int) {
    if root == nil {
        return
    }
    if root.Val == val {
        answer = root
        return
    }
    dfs(root.Left, val)
    dfs(root.Right, val)
}

func searchBST(root *TreeNode, val int) *TreeNode {
    answer = nil
    dfs(root, val)
    return answer
}