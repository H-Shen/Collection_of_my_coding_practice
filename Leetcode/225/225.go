// implement the stack using only one queue
type Queue struct {
	arr []int
}
func (this *Queue) Push(x int) {
	this.arr = append(this.arr, x)
}
func (this *Queue) Front() (int, error) {
	if len(this.arr) == 0 {
		return 0, errors.New("the queue is empty")
	}
	return this.arr[0], nil
}
func (this *Queue) Back() (int, error) {
	if len(this.arr) == 0 {
		return 0, errors.New("the queue is empty")
	}
	return this.arr[len(this.arr)-1], nil
}
func (this *Queue) Pop() (int, error) {
	if len(this.arr) == 0 {
		return 0, errors.New("the queue is empty")
	}
	temp := this.arr[len(this.arr)-1]
    this.arr = this.arr[:len(this.arr)-1]
	return temp, nil
}
func (this *Queue) Empty() bool {
	return len(this.arr) == 0
}

type MyStack struct {
	q Queue
}

func Constructor() MyStack {
	return MyStack{}
}

func (this *MyStack) Push(x int) {
	this.q.Push(x)
}

func (this *MyStack) Pop() int {
	val, _ := this.q.Pop()
	return val
}

func (this *MyStack) Top() int {
	val, _ := this.q.Back()
	return val
}

func (this *MyStack) Empty() bool {
	return this.q.Empty()
}


/**
 * Your MyStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Empty();
 */