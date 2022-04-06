package reorderlist

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

func reorderList(head *ListNode) {
	if head == nil {
		return
	}

	slow, fast := head, head

	for fast != nil {
		fast = fast.Next
		if fast == nil {
			break
		}
		fast = fast.Next
		if fast == nil {
			break
		}
		slow = slow.Next
	}

	h1 := head
	h2 := reverse(slow.Next)
	slow.Next = nil

	root := &ListNode{}
	p := root
	for h1 != nil && h2 != nil {
		p.Next = h1
		h1 = h1.Next
		p = p.Next
		p.Next = h2
		h2 = h2.Next
		p = p.Next
	}

	if h1 != nil {
		p.Next = h1
	}

	head = root.Next
	return
}
