const (
	MAX_LENGTH = 1e6 + 5
)

type MyHashMap struct {
	hashmap []int
}

func Constructor() MyHashMap {
	var myHashMap MyHashMap
	myHashMap.hashmap = make([]int, MAX_LENGTH)
	for i := 0; i < MAX_LENGTH; i++ {
		myHashMap.hashmap[i] = -1
	}
	return myHashMap
}

func (this *MyHashMap) Put(key int, value int) {
	this.hashmap[key] = value
}

func (this *MyHashMap) Get(key int) int {
	return this.hashmap[key]
}

func (this *MyHashMap) Remove(key int) {
	this.hashmap[key] = -1
}


/**
 * Your MyHashMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Put(key,value);
 * param_2 := obj.Get(key);
 * obj.Remove(key);
 */