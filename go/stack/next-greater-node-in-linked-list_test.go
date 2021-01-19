package stack

import (
	"testing"
)

func createLargerNodes(arr []int) (head *ListNode) {
	var node *ListNode
	for i := len(arr) - 1; i >= 0; i-- {
		tmp := &ListNode{
			Val: arr[i],
			Next: node,
		}

		node = tmp
	}

	head = node
	return
}
func TestNextLargerNodes(t *testing.T) {
	head := createLargerNodes([]int{2,1,5})
	target := []int{5,5,0}
	arr := nextLargerNodes(head)
	for i := 0; i < len(arr); i++ {
		if arr[i] != target[i] {
			t.Fatalf("test failed, [%d]:%d - %d", i,arr[i], target[i])
		}
	}

	head = createLargerNodes([]int{2,2,5})
	target = []int{5,5,0}
	arr = nextLargerNodes(head)
	for i := 0; i < len(arr); i++ {
		if arr[i] != target[i] {
			t.Fatalf("test failed, [%d]:%d - %d", i,arr[i], target[i])
		}
	}

	head = createLargerNodes([]int{2,7,4,3,5})
	target = []int{7,0,5,5,0}
	arr = nextLargerNodes(head)
	for i := 0; i < len(arr); i++ {
		if arr[i] != target[i] {
			t.Fatalf("test failed, [%d]:%d - %d", i,arr[i], target[i])
		}
	}

	head = createLargerNodes([]int{1,7,5,1,9,2,5,1})
	target = []int{7,9,9,9,0,5,0,0}
	arr = nextLargerNodes(head)
	for i := 0; i < len(arr); i++ {
		if arr[i] != target[i] {
			t.Fatalf("test failed, [%d]:%d - %d", i,arr[i], target[i])
		}
	}
}
