package stack

type MyQueue struct {
	st []int
	top int
	dSt []int
	dTop int
}


/** Initialize your data structure here. */
func Constructor() MyQueue {
	return MyQueue{
		st : make([]int, 16),
		top: -1,

		dSt : make([]int, 16),
		dTop:  -1,
	}
}


func (this *MyQueue) MallocStack(st []int, top int)([]int)  {
	if top >= len(st)-1 {
		newSt := make([]int, 2 * len(st))
		copy(newSt,st)
		return newSt
	}

	return st
}

/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int)  {
	this.st = this.MallocStack(this.st, this.top)

	this.top++
	this.st[this.top] = x
}


/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
	val := this.Peek()
	this.dTop--
	return val
}


/** Get the front element. */
func (this *MyQueue) Peek() int {
	if this.dTop == -1 {
		for this.top > -1 {
			this.dSt = this.MallocStack(this.dSt, this.dTop)
			this.dTop++
			this.dSt[this.dTop] = this.st[this.top]
			this.top--
		}
	}

	val := this.dSt[this.dTop]
	return val
}


/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
	return this.top <= -1 && this.dTop <= -1
}


/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */