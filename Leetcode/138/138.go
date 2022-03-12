/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

func copyRandomList(head *Node) *Node {
	if head == nil {
		return nil
	}
	old2new := make(map[*Node]*Node)
	node := head
	beforeHead := new(Node)
	var currentNewNode *Node = nil
	for node != nil {
		temp := new(Node)
		temp.Val = node.Val
		temp.Next = nil
		temp.Random = nil
		if currentNewNode == nil {
			currentNewNode = temp
			beforeHead.Next = currentNewNode
		} else {
			currentNewNode.Next = temp
			currentNewNode = currentNewNode.Next
		}
		node = node.Next
	}
	node = head
	node2 := beforeHead.Next
	for node != nil {
		old2new[node] = node2
		node = node.Next
		node2 = node2.Next
	}
	node = head
	for node != nil {
		if node.Random != nil {
			old2new[node].Random = old2new[node.Random]	
		}
		node = node.Next
	}
	return beforeHead.Next
}