package sortlist

type ListNode struct {
	Val  int
	Next *ListNode
}

func sortList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	slow, fast := head, head
	for fast != nil {
		fast = fast.Next
		if fast == nil || fast.Next == nil {
			break
		}
		slow = slow.Next
		fast = fast.Next
	}

	next := slow.Next
	slow.Next = nil

	h1 := sortList(head)
	h2 := sortList(next)

	root := &ListNode{}
	p := root
	for h1 != nil && h2 != nil {
		if h1.Val <= h2.Val {
			p.Next = h1
			h1 = h1.Next
		} else {
			p.Next = h2
			h2 = h2.Next
		}
		p = p.Next
		p.Next = nil
	}
	if h2 != nil {
		h1 = h2
	}

	p.Next = h1

	return root.Next
}
