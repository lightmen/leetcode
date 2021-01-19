package stack

import "testing"

func TestMinRemoveToMakeValid(t *testing.T) {
	var s, result, expect string

	s = "lee(t(c)o)de)"
	expect = "lee(t(c)o)de"
	result = minRemoveToMakeValid(s)
	if result != expect {
		t.Fatalf("test failed: %s", result)
	}

	s = "a)b(c)d"
	expect = "ab(c)d"
	result = minRemoveToMakeValid(s)
	if result != expect {
		t.Fatalf("test failed: %s", result)
	}

	s = "))(("
	expect = ""
	result = minRemoveToMakeValid(s)
	if result != expect {
		t.Fatalf("test failed: %s", result)
	}

	s = "(a(b(c)d)"
	expect = "a(b(c)d)"
	result = minRemoveToMakeValid(s)
	if result != expect {
		t.Fatalf("test failed: %s", result)
	}
}
