/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	resultHead := new(ListNode)
	var tail *ListNode = nil
	counter := 0
	var lastVal int
	node := head
	for node != nil {
		if counter == 0 {
			lastVal = node.Val
			counter++
			node = node.Next
			continue
		}
		if lastVal != node.Val {
			if counter == 1 {
				if tail == nil {
					tail = new(ListNode)
					tail.Val = lastVal
					tail.Next = nil
					resultHead.Next = tail
				} else {
					temp := new(ListNode)
					temp.Val = lastVal
					temp.Next = nil
					tail.Next = temp
					tail = temp
				}
			}
			counter = 1
			lastVal = node.Val
		} else {
			counter++
		}
		node = node.Next
	}
	if counter == 1 {
		if tail == nil {
			tail = new(ListNode)
			tail.Val = lastVal
			tail.Next = nil
			resultHead.Next = tail
		} else {
			temp := new(ListNode)
			temp.Val = lastVal
			temp.Next = nil
			tail.Next = temp
			tail = temp
		}
	}
	return resultHead.Next
}