package binarytree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func bfs(node *TreeNode, level int, result [][]int) [][]int {
	if node == nil {
		return result
	}

	var arr []int
	if level > len(result)-1 {
		arr = make([]int, 0)
		result = append(result, arr)
	} else {
		arr = result[level]
	}

	arr = append(arr, node.Val)
	result[level] = arr
	if node.Left != nil {
		result = bfs(node.Left, level+1, result)
	}

	if node.Right != nil {
		result = bfs(node.Right, level+1, result)
	}

	return result
}

func levelOrder1(root *TreeNode) (result [][]int) {
	result = bfs(root, 0, result)
	return
}
