/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func hasCycle(head *ListNode) bool {
	if head == nil || head.Next == nil || head.Next.Next == nil {
		return false
	}
    // Floyd Cycle Detection
	slowNode := head.Next
	fastNode := head.Next.Next
	for slowNode != fastNode {
		if fastNode.Next == nil || fastNode.Next.Next == nil {
			return false
		}
		slowNode = slowNode.Next
		fastNode = fastNode.Next.Next
	}
	return true
}