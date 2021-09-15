/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type Tuple struct {
	val, l, r int
}

var (
	dp map[Tuple]int
	freq map[int]int
	id int
	ans []*TreeNode
)

func dfs(node *TreeNode) int {
	if node != nil {
		k := Tuple{
			val: node.Val,
			l:   dfs(node.Left),
			r:   dfs(node.Right),
		}
		val, ok := dp[k]
		if !ok {
			dp[k] = id
			freq[id]++
			id++
		} else {
			freq[val]++
			if freq[val] == 2 {
				ans = append(ans, node)
			}
		}
		return dp[k]
	}
	return -1
}

func findDuplicateSubtrees(root *TreeNode) []*TreeNode {
	dp = nil
	dp = make(map[Tuple]int)
	freq = nil
	freq = make(map[int]int)
	id = 0
	ans = nil
	_ = dfs(root)
	return ans
}