package getkthfromend

type ListNode struct {
	Val  int
	Next *ListNode
}

func getKthFromEnd(head *ListNode, k int) *ListNode {
	cnt := 0
	p := head
	for p != nil {
		cnt++
		p = p.Next
	}

	k = cnt - k
	for k > 0 {
		head = head.Next
		k--
	}

	return head
}
