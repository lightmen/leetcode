package balancedbinarytree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isBalanced(root *TreeNode) bool {
	_, ok := balanceHeight(root)
	return ok
}

func balanceHeight(root *TreeNode) (height int, isBalance bool) {
	if root == nil {
		isBalance = true
		return
	}

	lh, lb := balanceHeight(root.Left)
	if !lb {
		return
	}
	rh, rb := balanceHeight(root.Right)
	if !rb {
		return
	}

	subH := lh - rh
	if lh > rh {
		height = lh
	} else {
		height = rh
		subH = rh - lh
	}

	if subH <= 1 {
		isBalance = true
	}

	height++

	return
}
