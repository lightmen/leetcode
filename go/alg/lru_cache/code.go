package lrucache

import "container/list"

type node struct {
	key int
	val int
}

type LRUCache struct {
	*list.List
	MData map[int]*list.Element
	cap   int
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		cap:   capacity,
		List:  list.New(),
		MData: make(map[int]*list.Element),
	}
}

func (this *LRUCache) Get(key int) int {
	elem := this.MData[key]
	if elem == nil {
		return -1
	}

	this.MoveToFront(elem)
	node := elem.Value.(node)
	return node.val
}

func (this *LRUCache) Put(key int, value int) {
	elem := this.MData[key]
	if elem != nil {
		this.Remove(elem)
	} else if len(this.MData) >= this.cap {
		de := this.Back()
		node := de.Value.(node)
		delete(this.MData, node.key)
		this.Remove(de)
	}
	elem = this.PushFront(node{key, value})
	this.MData[key] = elem
}
