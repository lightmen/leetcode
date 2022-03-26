package reversenodesinkgroup

import "testing"

func TestReverseKGroup(t *testing.T) {
	head := &ListNode{
		Val: 1,
		Next: &ListNode{
			Val: 2,
			Next: &ListNode{
				Val: 3,
				Next: &ListNode{
					Val: 4,
					Next: &ListNode{
						Val: 5,
					},
				},
			},
		},
	}

	head = reverseKGroup(head, 2)

	for head != nil {
		t.Logf("%d\n", head.Val)
		head = head.Next
	}
}
