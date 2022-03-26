package inorder

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type Stack struct {
	data []interface{}
	top  int
}

func NewStack() *Stack {
	return &Stack{
		data: make([]interface{}, 0),
		top:  -1,
	}
}

func (st *Stack) Empty() bool {
	return st.top == -1
}

func (st *Stack) Pop() interface{} {
	if st.Empty() {
		panic("pop from emtpy stack")
	}

	val := st.data[st.top]
	st.top--
	return val
}

func (st *Stack) Push(val interface{}) {
	st.top++
	if len(st.data)-1 >= st.top {
		st.data[st.top] = val
	} else {
		st.data = append(st.data, val)
	}
}

//中序遍历，非递归
func inorderTraversal(root *TreeNode) (arr []int) {
	if root == nil {
		return
	}

	st := NewStack()
	last := root
	for !st.Empty() || last != nil {
		for last != nil {
			st.Push(last)
			last = last.Left
		}

		node := st.Pop().(*TreeNode)
		arr = append(arr, node.Val)
		if node.Right != nil {
			last = node.Right
		}
	}

	return
}
