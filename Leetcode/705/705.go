const (
	MAX_LENGTH = 1e6+5
)

type MyHashSet struct {
	vis []bool
}

func Constructor() MyHashSet {
	return MyHashSet{vis: make([]bool, MAX_LENGTH)}
}

func (this *MyHashSet) Add(key int) {
	this.vis[key] = true
}

func (this *MyHashSet) Remove(key int) {
	this.vis[key] = false
}

func (this *MyHashSet) Contains(key int) bool {
	return this.vis[key]
}


/**
 * Your MyHashSet object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(key);
 * obj.Remove(key);
 * param_3 := obj.Contains(key);
 */