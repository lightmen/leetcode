package lfucache

import (
	"container/list"
	"math"
)

type node struct {
	key  int
	val  int
	freq int
}

type LFUCache struct {
	freqs   map[int]*list.List
	nodes   map[int]*list.Element
	cap     int
	minFreq int
}

func Constructor(capacity int) LFUCache {
	return LFUCache{
		freqs:   make(map[int]*list.List),
		nodes:   make(map[int]*list.Element),
		cap:     capacity,
		minFreq: math.MaxInt,
	}
}

func (this *LFUCache) Get(key int) int {
	if this.cap == 0 {
		return -1
	}

	elem := this.nodes[key]
	if elem == nil {
		return -1
	}

	nod := elem.Value.(*node)
	this.removeElem(elem)
	nod.freq++
	elem = this.addToFreqs(nod)
	this.addToNodes(elem)
	return nod.val
}

func (this *LFUCache) addToFreqs(nod *node) *list.Element {
	lst := this.freqs[nod.freq]
	if lst == nil {
		lst = list.New()
		this.freqs[nod.freq] = lst
	}

	return lst.PushFront(nod)
}

func (this *LFUCache) erase() {
	lst := this.freqs[this.minFreq]
	if lst == nil {
		return
	}

	elem := lst.Back()
	key := elem.Value.(*node).key
	this.removeElem(elem)
	this.nodes[key] = nil
	delete(this.nodes, key)
}

func (this *LFUCache) removeElem(elem *list.Element) {
	nod := elem.Value.(*node)
	this.freqs[nod.freq].Remove(elem)
	if this.freqs[nod.freq].Len() == 0 {
		this.freqs[nod.freq] = nil
		delete(this.freqs, nod.freq)
		if nod.freq == this.minFreq {
			this.minFreq = math.MaxInt
		}
	}

	return
}

func (this *LFUCache) addToNodes(elem *list.Element) {
	nod := elem.Value.(*node)
	this.nodes[nod.key] = elem
	if nod.freq < this.minFreq {
		this.minFreq = nod.freq
	}

	return
}

func (this *LFUCache) Put(key int, value int) {
	if this.cap == 0 {
		return
	}

	elem := this.nodes[key]
	if elem == nil {
		if len(this.nodes) >= this.cap {
			this.erase()
		}
		nod := &node{
			key:  key,
			val:  value,
			freq: 1,
		}
		elem = this.addToFreqs(nod)
		this.addToNodes(elem)
		return
	}

	this.removeElem(elem)

	nod := elem.Value.(*node)
	nod.freq++
	nod.val = value
	elem = this.addToFreqs(nod)
	this.addToNodes(elem)

	return
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
