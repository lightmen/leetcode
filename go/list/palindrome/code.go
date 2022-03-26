package palindrome

type ListNode struct {
	Val  int
	Next *ListNode
}

func invert(head *ListNode) *ListNode {
	root := &ListNode{
		Next: nil,
	}

	for head != nil {
		tmp := head.Next
		head.Next = root.Next
		root.Next = head
		head = tmp
	}

	return root.Next
}

func isPalindrome(head *ListNode) bool {
	if head == nil {
		return true
	}
	slow := head
	fast := head
	for slow != nil && fast != nil {
		slow = slow.Next
		fast = fast.Next
		if fast != nil {
			fast = fast.Next
		}
	}

	slow = invert(slow)

	for slow != nil {
		if slow.Val != head.Val {
			return false
		}
		slow = slow.Next
		head = head.Next
	}

	return true
}
