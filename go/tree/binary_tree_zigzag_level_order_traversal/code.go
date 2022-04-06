package zigzaglevelorder

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func reverse(arr []int) {
	i, j := 0, len(arr)-1
	for i < j {
		arr[i], arr[j] = arr[j], arr[i]
		i++
		j--
	}
}

func zigzagLevelOrder(root *TreeNode) (result [][]int) {
	if root == nil {
		return
	}

	q := []*TreeNode{root}
	leftFirst := true
	for len(q) > 0 {
		var p []*TreeNode
		var arr []int
		for _, node := range q {
			arr = append(arr, node.Val)
			if node.Left != nil {
				p = append(p, node.Left)
			}
			if node.Right != nil {
				p = append(p, node.Right)
			}
		}
		if !leftFirst {
			reverse(arr)
		}
		leftFirst = !leftFirst
		result = append(result, arr)
		q = p
	}

	return
}
