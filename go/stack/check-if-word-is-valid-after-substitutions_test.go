package stack

import "testing"

func TestIsValid1(t *testing.T) {
	var s string
	s = "aabcbc"
	if !isValid1(s) {
		t.Fatalf("test failed")
	}

	s = "abcabcababcc"
	if !isValid1(s) {
		t.Fatalf("test failed")
	}


	s = "abccba"
	if isValid1(s) {
		t.Fatalf("test failed")
	}


	s = "cababc"
	if isValid1(s) {
		t.Fatalf("test failed")
	}
}
