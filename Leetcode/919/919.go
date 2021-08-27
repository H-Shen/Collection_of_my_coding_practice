/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
const MAXN int = 1005
type CBTInserter struct {
	v []*TreeNode
}

func getHeight(root *TreeNode) int {
	if root.Left != nil && root.Right != nil {
		a, b := getHeight(root.Left), getHeight(root.Right)
		if a > b {
			return 1+a
		}
		return 1+b
	} else if root.Left != nil && root.Right == nil {
		return 1+getHeight(root.Left)
	} else if root.Left == nil && root.Right != nil {
		return 1+getHeight(root.Right)
	}
	return 1
}

func Constructor(root *TreeNode) CBTInserter {
	res := CBTInserter{}
	res.v = nil
	if root != nil {
		vec := make([][]*TreeNode, getHeight(root))
		type Pair struct {
			first *TreeNode
			second int
		}
		queue := make(chan Pair, MAXN)
		queue <- Pair{root, 0}
		for len(queue) > 0 {
			pair := <- queue
			node := pair.first
			level := pair.second
			vec[level] = append(vec[level], node)
			if node.Left != nil {
				queue <- Pair{node.Left, level+1}
			}
			if node.Right != nil {
				queue <- Pair{node.Right, level+1}
			}
		}
		res.v = append(res.v, nil)
		for _, i := range vec {
			for _, j := range i {
				res.v = append(res.v, j)
			}
		}
	}
	return res
}

func (this *CBTInserter) Insert(val int) int {
	node := &TreeNode{Val: val, Left: nil, Right: nil}
	this.v = append(this.v, node)
	id := len(this.v)-1
	if (id & 1) != 0 {
		this.v[id >> 1].Right = node
	} else {
		this.v[id >> 1].Left = node
	}
	return this.v[id >> 1].Val
}

func (this *CBTInserter) Get_root() *TreeNode {
	return this.v[1]
}


/**
 * Your CBTInserter object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Insert(val);
 * param_2 := obj.Get_root();
 */