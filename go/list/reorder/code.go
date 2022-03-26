package reorder

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverse(head *ListNode) *ListNode {
	root := &ListNode{}

	for head != nil {
		tmp := head.Next
		head.Next = root.Next
		root.Next = head
		head = tmp
	}

	return root.Next
}

func reorderList(head *ListNode) {
	if head == nil {
		return
	}

	slow, fast := head, head
	prev := slow
	for slow != nil && fast != nil {
		prev = slow
		slow = slow.Next
		fast = fast.Next
		if fast != nil {
			fast = fast.Next
		}
	}

	prev.Next = nil

	n1 := head
	n2 := reverse(slow)

	for n2 != nil {
		next1 := n1.Next
		next2 := n2.Next

		n1.Next = n2
		n2.Next = next1

		n1 = next1
		n2 = next2
	}
}
