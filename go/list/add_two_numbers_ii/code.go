package addtwonumbersii

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverse(head *ListNode) *ListNode {
	root := &ListNode{}
	for head != nil {
		next := head.Next
		head.Next = root.Next
		root.Next = head
		head = next
	}

	return root.Next
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	r1 := reverse(l1)
	r2 := reverse(l2)

	root := &ListNode{}
	cur := root

	token := 0
	for r1 != nil && r2 != nil {
		sum := r1.Val + r2.Val + token
		node := &ListNode{
			Val: sum % 10,
		}
		token = sum / 10
		cur.Next = node
		cur = cur.Next

		r1 = r1.Next
		r2 = r2.Next
	}

	tail := r1
	if r2 != nil {
		tail = r2
	}

	for tail != nil {
		sum := tail.Val + token
		node := &ListNode{
			Val: sum % 10,
		}
		token = sum / 10
		cur.Next = node
		cur = cur.Next
		tail = tail.Next
	}

	if token > 0 {
		node := &ListNode{
			Val: token,
		}
		cur.Next = node
		cur = cur.Next
	}

	return reverse(root.Next)
}
