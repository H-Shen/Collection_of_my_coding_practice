/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil {
		return head
	}
	node := head
	var list []*ListNode
	for node != nil {
		list = append(list, node)
		node = node.Next
	}
	if k >= len(list) {
		k %= len(list)
	}
	if k == 0 {
		return head
	}
	remain := len(list) - k
	list[len(list)-1].Next = list[0]
	list[remain-1].Next = nil
	return list[remain]
}