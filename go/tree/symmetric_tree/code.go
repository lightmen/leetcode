package symmetrictree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}

	ok := isSame(root.Left, root.Right)

	return ok
}

func isSame(left, right *TreeNode) bool {
	if left == nil && right == nil {
		return true
	}

	if left == nil || right == nil {
		return false
	}

	if left.Val != right.Val {
		return false
	}

	if !isSame(left.Left, right.Right) {
		return false
	}

	if !isSame(left.Right, right.Left) {
		return false
	}

	return true
}
