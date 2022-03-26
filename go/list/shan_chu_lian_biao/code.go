package shanchulianbiao

type ListNode struct {
	Val  int
	Next *ListNode
}

func deleteNode(head *ListNode, val int) *ListNode {
	root := &ListNode{
		Next: head,
	}
	cur := root
	for head != nil && head.Val != val {
		cur = head
		head = head.Next
	}

	if head == nil {
		return nil
	}

	cur.Next = head.Next
	head.Next = nil
	head = nil
	return root.Next
}
