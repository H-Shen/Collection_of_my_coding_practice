/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func dfs(root1 *TreeNode, root2 *TreeNode) {
    (*root1).Val += (*root2).Val
    if (*root1).Left != nil && (*root2).Left != nil {
        dfs((*root1).Left, (*root2).Left)
    } else if (*root1).Left == nil && (*root2).Left != nil {
        (*root1).Left = (*root2).Left
    }
    if (*root1).Right != nil && (*root2).Right != nil {
        dfs((*root1).Right, (*root2).Right)
    } else if (*root1).Right == nil && (*root2).Right != nil {
        (*root1).Right = (*root2).Right
    }
}

func mergeTrees(root1 *TreeNode, root2 *TreeNode) *TreeNode {
    if root1 == nil && root2 == nil {
        return nil
    } else if root1 != nil && root2 == nil {
        return root1
    } else if root1 == nil && root2 != nil {
        return root2
    }
    dfs(root1, root2)
    return root1
}