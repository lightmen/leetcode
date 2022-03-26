package postorder

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

func (st *Stack) Top() interface{} {
	if st.Empty() {
		return nil
	}

	val := st.data[st.top]
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

func postorderTraversal(root *TreeNode) (arr []int) {
	if root == nil {
		return
	}

	st := NewStack()
	cur := root

	var prev *TreeNode
	for !st.Empty() || cur != nil {
		for cur != nil {
			st.Push(cur)
			cur = cur.Left
		}
		if st.Empty() {
			continue
		}

		node := st.Top().(*TreeNode)
		if node.Right != nil && prev != node.Right {
			cur = node.Right
		} else if (node.Left == nil && node.Right == nil) ||
			(prev != nil && (node.Left == prev || node.Right == prev)) {
			arr = append(arr, node.Val)
			prev = node
			st.Pop()
		}
	}

	return
}
