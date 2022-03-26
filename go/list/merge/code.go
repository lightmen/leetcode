package merge

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
	} else {
		cur.Next = n2
	}

	return root.Next
}

func mergeKLists(lists []*ListNode) *ListNode {
	if len(lists) == 0 {
		return nil
	}
	if len(lists) == 1 {
		return lists[0]
	}

	if len(lists) == 2 {
		return merge(lists[0], lists[1])
	}

	ln := len(lists)
	n1 := mergeKLists(lists[:ln/2])
	n2 := mergeKLists(lists[ln/2:])

	return merge(n1, n2)
}
