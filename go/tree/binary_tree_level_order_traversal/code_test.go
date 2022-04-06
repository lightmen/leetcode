package binarytree

import "testing"

func TestLevelOrder(t *testing.T) {
	root := &TreeNode{
		Val: 1,
	}
	left := &TreeNode{
		Val: 2,
		Left: &TreeNode{
			Val: 4,
		},
	}
	right := &TreeNode{
		Val: 3,
	}

	root.Left = left
	root.Right = right

	result := levelOrder(root)
	t.Logf("%v", result)
}
