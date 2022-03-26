package kmp

import "testing"

func TestKmp(t *testing.T) {
	s := "rabaieet"
	p := "abai"

	idx := Kmp(s, p)
	t.Logf("idx: %d", idx)
}
