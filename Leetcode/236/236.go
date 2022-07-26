/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func dfs1(node *TreeNode, n *int) {
	if node != nil {
		*n++
		dfs1(node.Left, n)
		dfs1(node.Right, n)
	}
}

func dfs2(node *TreeNode, node2id *map[int]int, id *int) {
	if node != nil {
		(*node2id)[node.Val] = *id
		*id++
		dfs2(node.Left, node2id, id)
		dfs2(node.Right, node2id, id)
	}
}

func dfs3(node *TreeNode, fa *TreeNode, father []int, node2id *map[int]int) {
	if node != nil {
		if fa != nil {
			father[(*node2id)[node.Val]] = (*node2id)[fa.Val]
		} else {
			father[(*node2id)[node.Val]] = -1
		}
		dfs3(node.Left, node, father, node2id)
		dfs3(node.Right, node, father, node2id)
	}
}

var (
	result *TreeNode
)

func dfs4(root *TreeNode, node2id *map[int]int, targetId int) {
	if result != nil {
		return
	}
	if root != nil {
		if (*node2id)[root.Val] == targetId {
			result = root
			return
		}
		dfs4(root.Left, node2id, targetId)
		dfs4(root.Right, node2id, targetId)
	}
}

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	n := 0
	dfs1(root, &n)
	father := make([]int, n)
	node2id := make(map[int]int)
	id := 0
	dfs2(root, &node2id, &id)
	dfs3(root, nil, father, &node2id)
	pId := node2id[p.Val]
	unmap := make(map[int]struct{})
	for pId != -1 {
		unmap[pId] = struct{}{}
		pId = father[pId]
	}
	qId := node2id[q.Val]
	ans := -1
	for qId != -1 {
		if _, ok := unmap[qId]; ok {
			ans = qId
			break
		}
		qId = father[qId]
	}
	if ans == -1 {
		return nil
	}
	result = nil
	dfs4(root, &node2id, ans)
	return result
}