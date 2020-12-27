package stack

import "testing"

func TestPostorderTraversal(t *testing.T) {
	root := &TreeNode{
		Val: 3,
	}

	right := &TreeNode{
		Val: 2,
	}

	root.Right = right
	l2 := &TreeNode{
		Val: 1,
	}

	right.Left = l2

	result := postorderTraversal(root)
	for idx, val := range result {
		if val != idx +1 {
			t.Fatalf("test failed, idx: %d, result: %v", idx, result)
		}
	}
}
