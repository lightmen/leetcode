package oddevenlinkedlist

type ListNode struct {
	Val  int
	Next *ListNode
}

func oddEvenList(head *ListNode) *ListNode {
	oddRoot := &ListNode{}
	evenRoot := &ListNode{}
	odd := oddRoot
	even := evenRoot

	isOdd := true
	for head != nil {
		next := head.Next
		if isOdd {
			odd.Next = head
			odd = head
		} else {
			even.Next = head
			even = head
		}
		head.Next = nil
		head = next
		isOdd = !isOdd
	}

	odd.Next = evenRoot.Next
	return oddRoot.Next
}
