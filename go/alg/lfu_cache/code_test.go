package lfucache

import "testing"

func TestLFUCache(t *testing.T) {
	lfu := Constructor(2)
	lfu.Put(1, 1) // cache=[1,_], cnt(1)=1
	lfu.Put(2, 2) // cache=[2,1], cnt(2)=1, cnt(1)=1

	t.Log(lfu.Get(1)) // 返回 1
	// cache=[1,2], cnt(2)=1, cnt(1)=2

	lfu.Put(3, 3) // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
	// cache=[3,1], cnt(3)=1, cnt(1)=2

	t.Log(lfu.Get(2)) // 返回 -1（未找到）

	t.Log(lfu.Get(3)) // 返回 3
	// cache=[3,1], cnt(3)=2, cnt(1)=2

	lfu.Put(4, 4) // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
	// cache=[4,3], cnt(4)=1, cnt(3)=2

	t.Log(lfu.Get(1)) // 返回 -1（未找到）

	t.Log(lfu.Get(3)) // 返回 3
	// cache=[3,4], cnt(4)=1, cnt(3)=3

	t.Log(lfu.Get(4)) // 返回 4
	// cache=[3,4], cnt(4)=2, cnt(3)=3

}

func TestLFUCache1(t *testing.T) {
	lfu := Constructor(3)
	lfu.Put(2, 2)
	lfu.Put(1, 1)

	t.Log(lfu.Get(2)) //2
	t.Log(lfu.Get(1)) //1
	t.Log(lfu.Get(2)) //2

	lfu.Put(3, 3)
	lfu.Put(4, 4)

	t.Log(lfu.Get(3)) //-1
	t.Log(lfu.Get(2)) //2
	t.Log(lfu.Get(1)) //1
	t.Log(lfu.Get(4)) //4
}
