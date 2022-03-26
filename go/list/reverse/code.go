package reverse

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseList(head *ListNode) *ListNode {
	root := &ListNode{}
	for head != nil {
		tmp := head.Next
		head.Next = root.Next
		root.Next = head
		head = tmp
	}

	return root.Next
}
