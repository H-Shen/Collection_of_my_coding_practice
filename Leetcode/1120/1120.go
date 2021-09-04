/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var dp1, dp2 map[*TreeNode]int

func getTreeSum(node *TreeNode) int {
	val, ok := dp1[node]
	if ok {
		return val
	}
	dp1[node] = node.Val
	if node.Left != nil {
		dp1[node] += getTreeSum(node.Left)
	}
	if node.Right != nil {
		dp1[node] += getTreeSum(node.Right)
	}
	return dp1[node]
}

func getTreeSize(node *TreeNode) int {
	val, ok := dp2[node]
	if ok {
		return val
	}
	dp2[node] = 1
	if node.Left != nil {
		dp2[node] += getTreeSize(node.Left)
	}
	if node.Right != nil {
		dp2[node] += getTreeSize(node.Right)
	}
	return dp2[node]
}

func dfs(node *TreeNode, ans *float64) {
	if node != nil {
		*ans = math.Max(*ans, float64(getTreeSum(node))/float64(getTreeSize(node)))
		dfs(node.Left, ans)
		dfs(node.Right, ans)
	}
}

func maximumAverageSubtree(root *TreeNode) float64 {
	dp1 = nil
	dp1 = make(map[*TreeNode]int)
	dp2 = nil
	dp2 = make(map[*TreeNode]int)
	ans := float64(0)
	dfs(root, &ans)
	return ans
}