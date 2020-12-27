package stack

func postorderTraversal2(root *TreeNode) []int {
	var result []int

	if root == nil {
		return result
	}

	st := New()
	st.Push(root)
	var pre *TreeNode
	for !st.IsEmpty() {
		cur := st.Top().(*TreeNode)
		if (cur.Left == nil && cur.Right == nil) ||
			(pre != nil && (cur.Left == pre || cur.Right == pre)){
			result = append(result, cur.Val)
			st.Pop()
			pre = cur
		}else {
			if cur.Right != nil {
				st.Push(cur.Right)
			}

			if cur.Left != nil {
				st.Push(cur.Left)
			}
		}
	}

	return result
}

