/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxElement(nums []int, l int, r int) (int, int) {
	if l > r {
		panic("l should be not larger than r!")
	}
	ans, pos := math.MinInt32, l
	for i := l; i <= r; i++ {
		if nums[i] > ans {
			ans = nums[i]
			pos = i
		}
	}
	return ans, pos
}
func solve(nums []int, l int, r int) *TreeNode {
	if l > r {
		return nil
	}
	val, pos := maxElement(nums, l, r)
	node := new(TreeNode)
	node.Val = val
	node.Left = solve(nums, l, pos-1)
	node.Right = solve(nums, pos+1, r)
	return node
}
func constructMaximumBinaryTree(nums []int) *TreeNode {
	return solve(nums, 0, len(nums)-1)
}