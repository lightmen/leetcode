package removeduplicatesfromsortedlistii

type ListNode struct {
	Val  int
	Next *ListNode
}

func deleteDuplicates(head *ListNode) *ListNode {
	root := &ListNode{}
	cur := root

	for head != nil {
		val := head.Val
		cnt := 1
		for head.Next != nil && head.Next.Val == val {
			cnt++
			head = head.Next
		}

		next := head.Next

		if cnt > 1 {
			head = next
			continue
		}

		cur.Next = head
		cur = head
		head = next
	}

	cur.Next = nil

	return root.Next
}
