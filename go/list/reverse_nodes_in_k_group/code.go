package reversenodesinkgroup

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

func reverseKGroup(head *ListNode, k int) *ListNode {
	root := &ListNode{}

	cur := root
	for head != nil {
		cnt := k
		start := head
		for cnt > 1 && head != nil {
			cnt--
			head = head.Next
		}

		if head == nil {
			cur.Next = start
			return root.Next
		}

		next := head.Next
		head.Next = nil

		cur.Next = reverse(start)
		cur = start

		head = next
	}

	return root.Next
}
