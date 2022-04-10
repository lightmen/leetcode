package addtwonumbers

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	carry := 0
	root := &ListNode{}

	p := root
	for l1 != nil && l2 != nil {
		val := l1.Val + l2.Val + carry
		carry = val / 10
		val = val % 10

		node := &ListNode{
			Val: val,
		}
		p.Next = node
		p = node

		l1 = l1.Next
		l2 = l2.Next
	}

	if l2 != nil {
		l1 = l2
	}

	for l1 != nil {
		val := l1.Val + carry
		carry = val / 10
		val = val % 10

		node := &ListNode{
			Val: val,
		}
		p.Next = node
		p = node

		l1 = l1.Next
	}

	if carry > 0 {
		node := &ListNode{
			Val: carry,
		}
		p.Next = node
		p = node
	}

	return root.Next
}
