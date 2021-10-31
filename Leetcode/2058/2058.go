/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func nodesBetweenCriticalPoints(head *ListNode) []int {
	var arr []int
	node := head
	for node != nil {
		arr = append(arr, node.Val)
		node = node.Next
	}
	var vec[]int
	for i := 1; i < len(arr)-1; i++ {
		if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) || (arr[i] < arr[i-1] && arr[i] < arr[i+1]) {
			vec = append(vec, i)
		}
	}
	var ans []int
	if len(vec) < 2 {
		ans = append(ans, -1)
		ans = append(ans, -1)
		return ans
	}
	sort.Ints(vec)
	minVal := math.MaxInt32
	for i := 1; i < len(vec); i++ {
		minVal = min(minVal, vec[i]-vec[i-1])
	}
	maxVal := vec[len(vec)-1] - vec[0]
	ans = append(ans, minVal)
	ans = append(ans, maxVal)
	return ans
}