package detectcycle

import "testing"

func TestDetectCycle(t *testing.T) {
	n1 := &ListNode{
		Val: 3,
	}
	n2 := &ListNode{
		Val: 2,
	}
	n3 := &ListNode{
		Val: 0,
	}
	n4 := &ListNode{
		Val: -4,
	}

	n1.Next = n2
	n2.Next = n3
	n3.Next = n4
	n4.Next = n2

	node := detectCycle(n1)

	t.Logf("val: %d", node.Val)
}
