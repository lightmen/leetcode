package rotatelist

type ListNode struct {
	Val  int
	Next *ListNode
}

func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil {
		return nil
	}

	cur := head
	cnt := 0
	tail := cur
	for cur != nil {
		cnt++
		tail = cur
		cur = cur.Next
	}

	k = k % cnt
	k = cnt - k
	cur = &ListNode{
		Next: head,
	}

	cnt = 0
	for cur != nil && cnt != k {
		cur = cur.Next
		cnt++
	}

	tail.Next = head
	head = cur.Next
	cur.Next = nil

	return head
}
