package lrucache

import "testing"

func TestLRUCache(t *testing.T) {
	lru := Constructor(2)
	lru.Put(1, 1)     // 缓存是 {1=1}
	lru.Put(2, 2)     // 缓存是 {1=1, 2=2}
	t.Log(lru.Get(1)) // 返回 1
	lru.Put(3, 3)     // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
	t.Log(lru.Get(2)) // 返回 -1 (未找到)
	lru.Put(4, 4)     // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
	t.Log(lru.Get(1)) // 返回 -1 (未找到)
	t.Log(lru.Get(3)) // 返回 3
	t.Log(lru.Get(4)) // 返回 4

}
