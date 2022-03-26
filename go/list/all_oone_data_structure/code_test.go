package alloone

import "testing"

func TestAllOne1(t *testing.T) {
	hello := "hello"
	// goodBye := "goodbye"
	leet := "leet"
	// code := "code"
	obj := Constructor1()
	obj.Inc(hello)
	// obj.Inc(goodBye)
	obj.Inc(hello)
	obj.Inc(hello)
	t.Logf("max key :%s\n", obj.GetMaxKey())
	obj.Inc(leet)

	// obj.Inc(code)
	obj.Inc(leet)
	obj.Dec(hello)

	obj.Inc(leet)
	// obj.Inc(code)
	// obj.Inc(code)
	t.Logf("max key :%s\n", obj.GetMaxKey())
}

func TestAllOne(t *testing.T) {
	hello := "hello"
	leet := "leet"
	obj := Constructor()

	obj.Inc(leet)
	obj.Inc(hello)
	obj.Inc(hello)
	obj.Inc(hello)
	obj.Inc(hello)
	obj.Dec(hello)
	obj.Dec(hello)
	t.Logf("max key :%s\n", obj.GetMaxKey())

	t.Logf("max key :%s\n", obj.GetMaxKey())
}
