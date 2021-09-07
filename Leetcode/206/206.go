/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	if head.Next == nil {
		return head
	} else if head.Next.Next == nil {
		temp := head.Next
		head.Next = temp.Next
		temp.Next = head
		return temp
	}
	node := reverseList(head.Next)
	node.Next = head
	head.Next = nil
	return node
}