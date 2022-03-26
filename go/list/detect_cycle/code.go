package detectcycle

type ListNode struct {
	Val  int
	Next *ListNode
}

func detectCycle(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}

	slow, fast := head, head
	for slow != nil && fast != nil {
		slow = slow.Next
		fast = fast.Next
		if fast == nil || fast.Next == nil { //说明链表没有环
			return nil
		}

		fast = fast.Next

		if slow == fast {
			break
		}
	}

	for head != slow {
		head = head.Next
		slow = slow.Next
	}

	return head
}
