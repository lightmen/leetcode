package alloone

import "container/list"

type node struct {
	keys  map[string]struct{}
	count int
}

type AllOne struct {
	*list.List
	nodes map[string]*list.Element
}

func Constructor() AllOne {
	return AllOne{
		List:  list.New(),
		nodes: map[string]*list.Element{},
	}
}

func (a *AllOne) Inc(key string) {
	curElem := a.nodes[key]
	if curElem == nil {
		if a.Front() == nil || a.Front().Value.(*node).count > 1 {
			a.nodes[key] = a.PushFront(&node{keys: map[string]struct{}{key: {}}, count: 1})
		} else {
			a.Front().Value.(*node).keys[key] = struct{}{}
			a.nodes[key] = a.Front()
		}

		return
	}

	curNode := curElem.Value.(*node)
	nextElem := curElem.Next()
	if nextElem == nil || nextElem.Value.(*node).count > curNode.count+1 {
		a.nodes[key] = a.InsertAfter(&node{keys: map[string]struct{}{key: {}}, count: curNode.count + 1}, curElem)
	} else {
		nextElem.Value.(*node).keys[key] = struct{}{}
		a.nodes[key] = nextElem
	}

	delete(curNode.keys, key)
	if len(curNode.keys) == 0 {
		a.Remove(curElem)
	}
}

func (a *AllOne) Dec(key string) {
	curElem, ok := a.nodes[key]
	if !ok {
		return
	}

	elem := curElem.Value.(*node)
	if elem.count > 1 {
		prevElem := curElem.Prev()
		if prevElem == nil || prevElem.Value.(*node).count < elem.count-1 {
			a.nodes[key] = a.InsertBefore(&node{
				keys: map[string]struct{}{
					key: {},
				},
				count: elem.count - 1,
			}, curElem)
		} else {
			prevElem.Value.(*node).keys[key] = struct{}{}
			a.nodes[key] = prevElem
		}
	} else {
		delete(a.nodes, key)
	}

	delete(elem.keys, key)
	if len(elem.keys) == 0 {
		a.Remove(curElem)
	}
}

func (a *AllOne) GetMaxKey() string {
	elem := a.Back()
	if elem != nil {
		for key := range elem.Value.(*node).keys {
			return key
		}
	}

	return ""
}

func (a *AllOne) GetMinKey() string {
	elem := a.Front()
	if elem != nil {
		for key := range elem.Value.(*node).keys {
			return key
		}
	}

	return ""
}
