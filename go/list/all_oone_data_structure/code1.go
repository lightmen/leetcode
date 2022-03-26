package alloone

type listNode struct {
	Val  int
	Key  string
	Prev *listNode
	Next *listNode
}

func (root *listNode) pushFront(node *listNode) {
	node.Next = root.Next
	root.Next.Prev = node

	node.Prev = root
	root.Next = node
}

func (root *listNode) delete(node *listNode) {
	next := node.Next
	prev := node.Prev

	prev.Next = next
	next.Prev = prev

	node.Next = nil
	node.Prev = nil
}

//链表向前后移动一个位置
func (root *listNode) moveBack(node *listNode) {
	back := node.Next //node2为需要

	node.Next = back.Next
	back.Next.Prev = node

	prev := node.Prev

	node.Prev = back
	back.Next = node

	back.Prev = prev
	prev.Next = back
}

func (root *listNode) moveFront(node *listNode) {
	prev := node.Prev
	root.moveBack(prev)
}

type AllOne1 struct {
	Root  *listNode
	MData map[string]*listNode
}

func Constructor1() AllOne1 {
	a := AllOne1{
		MData: make(map[string]*listNode),
		Root:  new(listNode),
	}

	a.Root.Next = a.Root
	a.Root.Prev = a.Root

	return a
}

func (a *AllOne1) Inc(key string) {
	node, ok := a.MData[key]
	if !ok {
		node = &listNode{
			Key: key,
			Val: 1,
		}

		a.MData[key] = node
		a.Root.pushFront(node)
		return
	}

	node.Val++
	for node.Next != a.Root {
		if node.Next.Val >= node.Val {
			break
		}

		a.Root.moveBack(node)
	}
}

func (a *AllOne1) Dec(key string) {
	node, ok := a.MData[key]
	if !ok {
		return
	}
	node.Val--
	if node.Val == 0 {
		delete(a.MData, key)
		a.Root.delete(node)
		return
	}

	for node.Prev != a.Root {
		if node.Prev.Val <= node.Val {
			break
		}
		a.Root.moveFront(node)
	}
}

func (a *AllOne1) GetMaxKey() string {
	node := a.Root.Prev
	if node == a.Root {
		return ""
	}

	return node.Key
}

func (a *AllOne1) GetMinKey() string {
	node := a.Root.Next
	if node == a.Root {
		return ""
	}

	return node.Key
}
