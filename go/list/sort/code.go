package sort

type ListNode struct {
	Val  int
	Next *ListNode
}

func merge(n1, n2 *ListNode) *ListNode {
	root := &ListNode{}
	cur := root
	var tmp *ListNode
	for n1 != nil && n2 != nil {

		if n1.Val <= n2.Val {
			tmp = n1
			n1 = n1.Next
		} else {
			tmp = n2
			n2 = n2.Next
		}
		cur.Next = tmp
		cur = tmp
	}

	if n1 != nil {
		cur.Next = n1
	} else if n2 != nil {
		cur.Next = n2
	}

	return root.Next
}

func sortList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
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
	head = sortList(head)
	slow = sortList(slow)

	return merge(head, slow)
}
