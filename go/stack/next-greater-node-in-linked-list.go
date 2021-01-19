package stack

type ListNode struct {
	Val int
   	Next *ListNode
}

func nextLargerNodes(head *ListNode) []int {
	arr := make([]int, 0)
	for head != nil {
		arr = append(arr, head.Val)
		head = head.Next
	}

	ret := make([]int, len(arr))
	st := make([]int, len(arr))
	top := -1
	for i := len(arr)-1; i >= 0; i-- {
		for top > -1 && arr[i] >=  st[top] {
			top--
		}

		if top > -1 {
			ret[i] = st[top]
		}
		top++
		st[top] = arr[i]
	}

	return ret
}
