/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func middleNode(head *ListNode) *ListNode {
	node := head
	counter := 0
	for node != nil {
		counter++
		node = node.Next
	}
	half := counter >> 1
	var prev = new(ListNode)
	prev.Next = head
    fmt.Println(half)
	for half > 0 {
		prev = prev.Next
		half--
	}
	return prev.Next
}