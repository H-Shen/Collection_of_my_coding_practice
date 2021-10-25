type Stack struct {
	arr []int
}
func (s *Stack) Push(val int) {
	s.arr = append(s.arr, val)
}
func (s *Stack) Empty() bool {
	return len(s.arr) == 0
}
func (s *Stack) Top() (val int, err error)  {
	if s.Empty() {
		return 0, errors.New("the stack is empty")
	}
	return s.arr[len(s.arr)-1], nil
}
func (s *Stack) Pop() {
	if !s.Empty() {
		s.arr = s.arr[:(len(s.arr)-1)]
	}
}
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

type MinStack struct {
	s, sMin Stack
}


func Constructor() MinStack {
	return MinStack{}
}


func (this *MinStack) Push(v int)  {
	if val, err := this.sMin.Top(); err == nil {
		this.s.Push(v)
		this.sMin.Push(min(val, v))
	} else {
		this.s.Push(v)
		this.sMin.Push(v)
	}
}


func (this *MinStack) Pop()  {
	this.s.Pop()
	this.sMin.Pop()
}


func (this *MinStack) Top() int {
	val, _ := this.s.Top()
	return val
}


func (this *MinStack) GetMin() int {
	val, _ := this.sMin.Top()
	return val
}


/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(val);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */