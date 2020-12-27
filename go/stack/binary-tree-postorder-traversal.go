package stack

type TreeNode struct {
     Val int
     Left *TreeNode
     Right *TreeNode
}

func postorderTraversal(root *TreeNode) []int {
	var result []int

	if root == nil {
		return result
	}

	st := New()
	st.Push(root)
	for  !st.IsEmpty() {
		tmp := st.Pop().(*TreeNode)
		result = append(result, tmp.Val)

		cur := tmp.Left
		if cur != nil {
			st.Push(cur)
			cur = cur.Left
		}

		cur = tmp.Right
		if cur != nil {
			st.Push(cur)
			cur = cur.Right
		}
	}
	i, j := 0, len(result)-1
	for i < j {
		result[i], result[j] = result[j], result[i]
		i++
		j--
	}
	return result
}
