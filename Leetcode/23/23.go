/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
const MAX_VALUE = 0x3f3f3f3f

// O(k*max(len(lists[i]))
func mergeKLists(lists []*ListNode) *ListNode {
	// Corner case
	if len(lists) == 0 {
		return nil
	}
    head := new(ListNode)
	var currentNode *ListNode = nil
	// Collect all nodes such that each node is the header of each linked list
	var nodes = make([]*ListNode, len(lists))
	for i := 0; i < len(lists); i++ {
		nodes[i] = lists[i]
	}
	for {
		// Scan again if any node in the list of linked list does not reach the end
		scanAgain := false
		temp := make([]int, len(nodes))
 		for i := 0; i < len(nodes); i++ {
			if nodes[i] == nil {
				temp[i] = MAX_VALUE
			} else {
				scanAgain = true
				temp[i] = nodes[i].Val
			}
		}
		if !scanAgain {
			break
		}
		minVal := MAX_VALUE
		minValIndex := 0
		for i := 0; i < len(temp); i++ {
			if temp[i] < minVal {
				minVal = temp[i]
				minValIndex = i
			}
		}
		if currentNode == nil {
			currentNode = new(ListNode)
			currentNode.Val = minVal
	        head.Next = currentNode
			currentNode.Next = nil
		} else {
			tempNode := new(ListNode)
			tempNode.Val = minVal
			tempNode.Next = nil
			currentNode.Next = tempNode
			currentNode = tempNode
		}
		nodes[minValIndex] = nodes[minValIndex].Next
	}
	return head.Next
}