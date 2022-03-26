package tree_from_preorder_traversal

//https://leetcode-cn.com/problems/construct-binary-search-tree-from-preorder-traversal/

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func bstFromPreorder(preorder []int) *TreeNode {
	return bstOrder(preorder, 0, len(preorder)-1)
}

func bstOrder(preorder []int, start, end int) (head *TreeNode) {
	if start > end {
		return
	}
	head = &TreeNode{
		Val: preorder[start],
	}
	if start == end {
		return
	}

	idx := start + 1
	for ; idx <= end; idx++ {
		if preorder[idx] > head.Val {
			break
		}
	}

	head.Left = bstOrder(preorder, start+1, idx-1)
	head.Right = bstOrder(preorder, idx, end)
	return
}
