const (
	INF = -1
	MAX_NODES = 2005
)

type LockingTree struct {
	parent []int
	lock []int
	AL [][]int
}

func Constructor(parent []int) LockingTree {
	var lockingTree LockingTree
	lockingTree.parent = parent
    lockingTree.lock = make([]int, len(parent))
	for i := 0; i < len(lockingTree.lock); i++ {
		lockingTree.lock[i] = INF
	}
	lockingTree.AL = make([][]int, len(parent))
	for i := 0; i < len(parent); i++ {
        if parent[i] != -1 {
            lockingTree.AL[parent[i]] = append(lockingTree.AL[parent[i]], i)
        }
	}
	return lockingTree
}

func (this *LockingTree) Lock(num int, user int) bool {
	if this.lock[num] == INF {
		this.lock[num] = user
		return true
	}
	return false
}

func (this *LockingTree) Unlock(num int, user int) bool {
	if this.lock[num] == user {
		this.lock[num] = INF
		return true
	}
	return false
}

func (this *LockingTree) Upgrade(num int, user int) bool {
	if this.lock[num] != INF {
		return false
	}
	temp := num
	for {
		temp = this.parent[temp]
		if temp == -1 {
			break
		}
		if this.lock[temp] != INF {
			return false
		}
	}
	// bfs to check if the node has at least one locked descendant (by any user)
	queue := make(chan int, MAX_NODES)
	queue <- num
	lockedDesc := false
	for len(queue) > 0 {
		node := <- queue
		for _, val := range this.AL[node] {
			if this.lock[val] != INF {
				lockedDesc = true
				break
			}
			queue <- val
		}
		if lockedDesc {
			break
		}
	}
	if lockedDesc {
		queue2 := make(chan int, MAX_NODES)
		queue2 <- num
		for len(queue2) > 0 {
			node := <- queue2
			for _, val := range this.AL[node] {
                this.lock[val] = INF
				queue2 <- val
			}
		}
		this.lock[num] = user
		return true
	}
	return false
}


/**
 * Your LockingTree object will be instantiated and called as such:
 * obj := Constructor(parent);
 * param_1 := obj.Lock(num,user);
 * param_2 := obj.Unlock(num,user);
 * param_3 := obj.Upgrade(num,user);
 */