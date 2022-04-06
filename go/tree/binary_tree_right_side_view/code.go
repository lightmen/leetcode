package binarytreerightsideview

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}
package binarytreerightsideview

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func rightSideView(root *TreeNode) (arr []int) {
	if root == nil {
		return
	}

	p := []*TreeNode{root}

	for len(p) != 0 {
		arr = append(arr, p[len(p)-1].Val)

		var q []*TreeNode
		for _, node := range p {
			if node.Left != nil {
				q = append(q, node.Left)
			}
			if node.Right != nil {
				q = append(q, node.Right)
			}
		}

		p = q
	}

	return
}
