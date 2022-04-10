package removenthnodefromendlist

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	root := &ListNode{
		Next: head,
	}

	cnt := 0
	for head != nil {
		cnt++
		head = head.Next
	}

	n = cnt - n

	p := root
	for n > 0 && p != nil {
		p = p.Next
		n--
	}

	if p == nil || p.Next == nil {
		return root.Next
	}

	p.Next = p.Next.Next

	return root.Next
}
