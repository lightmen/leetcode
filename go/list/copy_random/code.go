package copyrandom

type Node struct {
	Val    int
	Next   *Node
	Random *Node
}

func copyRandomList(head *Node) *Node {
	if head == nil {
		return nil
	}

	cur := head
	for cur != nil {
		next := cur.Next
		node := &Node{
			Val:  cur.Val,
			Next: next,
		}
		cur.Next = node
		cur = next
	}

	cur = head
	for cur != nil {
		if cur.Random != nil {
			cur.Next.Random = cur.Random.Next
		}
		cur = cur.Next.Next
	}

	cur = head
	root := &Node{}
	p := root
	for cur != nil {
		p.Next = cur.Next
		p = p.Next

		cur.Next = p.Next
		cur = cur.Next
	}
	p.Next = nil

	return root.Next
}
