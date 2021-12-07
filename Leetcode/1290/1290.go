/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getDecimalValue(head *ListNode) int {
	node := head
	var runes []rune
	for node != nil {
		runes = append(runes, rune(node.Val+'0'))
		node = node.Next
	}
	ans, err := strconv.ParseInt(string(runes), 2, 64)
	if err != nil {
		log.Fatalln(err)
	}
	return int(ans)
}