package binarytree

func levelOrder(root *TreeNode) (result [][]int) {
	if root == nil {
		return
	}

	q := []*TreeNode{root}

	for len(q) > 0 {
		var p []*TreeNode
		arr := make([]int, 0)
		for _, node := range q {
			arr = append(arr, node.Val)
			if node.Left != nil {
				p = append(p, node.Left)
			}
			if node.Right != nil {
				p = append(p, node.Right)
			}
		}
		result = append(result, arr)
		q = p
	}

	return
}
