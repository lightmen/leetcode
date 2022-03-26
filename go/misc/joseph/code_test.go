package joseph

import "testing"

func TestJoseph(t *testing.T) {
	n := 11
	m := 3

	idx := Joseph(n, m)
	if idx != 7 {
		t.Fatalf("test failed: %d", idx)
	}
}
