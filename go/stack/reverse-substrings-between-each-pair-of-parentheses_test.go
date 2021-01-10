package stack

import "testing"

func TestReverseParentheses(t *testing.T) {
	s := "(abcd)"
	rs := reverseParentheses(s)
	if rs != "dcba" {
		t.Fatalf("test failed: %s", rs)
	}

	s = "(u(love)i)"
	rs = reverseParentheses(s)
	if rs != "iloveu" {
		t.Fatalf("test failed: %s", rs)
	}

	s = "(ed(et(oc))el)"
	rs = reverseParentheses(s)
	if rs != "leetcode" {
		t.Fatalf("test failed: %s", rs)
	}

	s = "a(bcdefghijkl(mno)p)q"
	rs = reverseParentheses(s)
	if rs != "apmnolkjihgfedcbq" {
		t.Fatalf("test failed: %s", rs)
	}
}
