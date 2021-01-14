package stack

import "testing"

func TestQueue(t *testing.T) {
	queue := Constructor()

	queue.Push(1)
	queue.Push(2)
	queue.Push(3)
	val := queue.Peek()
	if val != 1 {
		t.Fatalf("test failed, val: %d", val)
	}

	queue.Pop()
	if queue.Empty() {
		t.Fatalf("test failed")
	}
}
